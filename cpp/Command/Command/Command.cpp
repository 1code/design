//Command.cpp

#include "Command.h"
#include "Receiver.h"
#include <iostream>

using namespace std;

Command::Command(Document* doc) {
	_doc = doc;
};

Command::~Command() {

};

void Command::Excute() {

};

OpenCommand::OpenCommand(Document* doc): Command(doc) {
	cout << "OpenCommand Constructor" << endl;
};

OpenCommand::~OpenCommand() { 
	cout << "OpenCommand Destructor" << endl;
};

void OpenCommand::Excute() {
	_doc->Open();	
};

PasteCommand::PasteCommand(Document *doc): Command(doc) {
	cout << "PasteCommand Constructor" << endl;
};

PasteCommand::~PasteCommand() { 
	cout << "PasteCommand Destructor" << endl;
};

void PasteCommand::Excute() {
	_doc->Paste(); 
};

