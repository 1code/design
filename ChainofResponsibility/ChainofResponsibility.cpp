#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Handler {
protected:
    unique_ptr<Handler> _next;
public:
    Handler() { _next = nullptr; }

    virtual void request(int value) = 0;

    void setNextHandler(unique_ptr<Handler> && next) {
        _next = move(next);
    }
};

class specialHandler : public Handler {
public:
    specialHandler(int limit, int id) {
        _limit = limit; 
        _id = id;
    }

    void request(int value) {
        if (value < _limit) {
            cout << "Handler " << _id << " handled the request " << value << " with a limit of " << _limit << endl;
        }
        else if (_next != nullptr) {
            _next->request(value);
        }
        else { 
            cout << "Sorry, I am the last handler " << _id << " and I couldn't even handle that request " << value << endl; 
        }
    }

private:
    int _limit;
    int _id;
};


int main ()
{
    unique_ptr<Handler> h1 = unique_ptr<Handler>(new specialHandler(10, 1));
    unique_ptr<Handler> h2 = unique_ptr<Handler>(new specialHandler(20, 2));
    unique_ptr<Handler> h3 = unique_ptr<Handler>(new specialHandler(30, 3));

    h2->setNextHandler(move(h3));
    h1->setNextHandler(move(h2));

    h1->request(9);
    h1->request(18);
    h1->request(25);
    h1->request(40);

    return 0;
}

