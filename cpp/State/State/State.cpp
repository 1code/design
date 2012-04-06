#include "State.h"
#include "Context.h"
#include <iostream>

using namespace std;

TCPState::TCPState() {

};

TCPState::~TCPState() {

};

void TCPState::ActiveOpen(TCPConn* con) {

};

void TCPState::PassiveOpen(TCPConn* con) {

};

void TCPState::Transmit(TCPConn* con) {

};

void TCPState::SendRequest(TCPConn* con) {

};

void TCPState::Close(TCPConn* con) {

};

bool TCPState::ChangeState(TCPConn* con, TCPState* st) {
//	cout << "State ChangeState" << endl;
	con->ChangeState(st);
	return true;
};

TCPEstablished::TCPEstablished() {
	cout << "TCPEstablished Constructor" << endl; 
};

TCPEstablished::~TCPEstablished() {
	cout << "TCPEstablished Destructor" << endl;
};

void TCPEstablished::Transmit(TCPConn* con) {
	cout << "TCPEstablished Transmit" << endl;
};

void TCPEstablished::Close(TCPConn* con) {
	cout << "TCPEstablished Close" << endl;
	this->ChangeState(con, new TCPClosed());
};

TCPListenning::TCPListenning() {
	cout << "TCPListenning Constructor" << endl; 
};

TCPListenning::~TCPListenning() {
	cout << "TCPListenning Destructor" << endl;
};

void TCPListenning::SendRequest(TCPConn* con) {
	cout << "TCPListenning SendRequest" << endl;
	this->ChangeState(con, new TCPEstablished());
};

TCPClosed::TCPClosed() {
	cout << "TCPClosed Constructor" << endl; 
};

TCPClosed::~TCPClosed() {
	cout << "TCPClosed Destructor" << endl;
};

void TCPClosed::ActiveOpen(TCPConn* con) {
	cout << "TCPClosed ActiveOpen" << endl;
	this->ChangeState(con, new TCPEstablished());
};

void TCPClosed::PassiveOpen(TCPConn* con) {
	cout << "TCPClosed PassiveOpen" << endl;
	this->ChangeState(con, new TCPListenning());
};

