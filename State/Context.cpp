#include "Context.h"
#include "State.h"
#include <iostream>

using namespace std;

TCPConn::TCPConn() {
	cout << "TCPConn Contructor" << endl;
	this->_state = new TCPClosed();
};

TCPConn::~TCPConn() {
	cout << "TCPConn Detructor" << endl;
	delete _state;
};

void TCPConn::ActiveOpen() {
	_state->ActiveOpen(this);
};

void TCPConn::PassiveOpen() {
	_state->PassiveOpen(this);
};

void TCPConn::Transmit() {
	_state->Transmit(this);
};

void TCPConn::SendRequest() {
	_state->SendRequest(this);
};

void TCPConn::Close() {
	_state->Close(this);
};

bool TCPConn::ChangeState(TCPState* state) {
	this->_state = state;
	return true;
};


