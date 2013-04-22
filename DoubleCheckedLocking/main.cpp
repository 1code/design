//main.cpp

#include "Singleton.h"
#include <vector>

using namespace std;

int main() {

    vector<thread> threads;
    for(int i = 0; i < 5; ++i) {
        threads.push_back(thread([]() {
            Singleton::instance();
            cout << "thread " << this_thread::get_id() << " get instance" << endl;
        }));
    }

    for(auto& thread : threads){
        thread.join();
    }

    return 0;
}

