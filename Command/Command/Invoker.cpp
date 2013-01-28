#include "Command.h"
#include "Invoker.h"
#include <iostream>

using namespace std;

Application::Application() {
	cout << "Application Constructor" << endl;
};

Application::~Application() {
	cout << "Application Destructor" << endl;
};

void Application::Add(Command* cmd) {
	cout << "Application Add" << endl;
	_cmd = cmd;
};

void Application::Excute() {
	cout << "Application Excute" << endl;
	_cmd->Excute();
};
