//main.cpp

#include "Command.h"
#include "Invoker.h"
#include "Receiver.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[]) {
    Application *app = new Application();
    Document* doc = new Document();
    Command * op = new OpenCommand(doc);
    Command * ps = new PasteCommand(doc);
    app->Add(op);
    app->Excute();
    app->Add(ps);
    app->Excute();
    if (op != NULL)
        delete op;
    if (ps != NULL)
        delete ps;
    if (doc != NULL)
        delete doc;
    if (app != NULL)
        delete app;
}
