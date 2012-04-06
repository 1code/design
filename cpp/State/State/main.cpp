#include "Context.h"
#include "State.h"
#include <iostream>

using namespace std;

int main() {
    TCPConn* con = new TCPConn();
    con->PassiveOpen();
    con->SendRequest();
    con->Transmit();
    con->Close();
    con->ActiveOpen();
    con->Transmit();
    con->Close();
    if (con != NULL)
        delete con;
    return 0;
};