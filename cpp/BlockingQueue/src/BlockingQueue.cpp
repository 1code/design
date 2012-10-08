//============================================================================
// implement a simple thread-safe multiple producer, multiple consumer queue
//============================================================================

#include <iostream>
#include <queue>
#include <pthread.h>
#include <cstdio>

#define NUM_THREADS 5

using namespace std;

template <typename T>
class Queue {
private:
    static pthread_mutex_t _mutex;
    static pthread_cond_t _cond;
    queue<T> _queue;
public:
    void push(const T &t) {
        pthread_mutex_lock(&_mutex);
        _queue.push(t);
        pthread_mutex_unlock(&_mutex);
        pthread_cond_signal(&_cond);
    }

    bool empty() const {
        pthread_mutex_lock(&_mutex);
        bool res = _queue.empty();
        pthread_mutex_unlock(&_mutex);
        return res;
    }

    bool nonblocking_pop(T &t) {
        pthread_mutex_lock(&_mutex);
        if (_queue.empty()) {
            return false;
        }
        t = _queue.front();
        _queue.pop();
        pthread_mutex_unlock(&_mutex);
        return true;
    }

    void blocking_pop(T &t) {
        pthread_mutex_lock(&_mutex);
        while (_queue.empty()) {
            pthread_cond_wait(&_cond, &_mutex);
        }
        t = _queue.front();
        _queue.pop();
        pthread_mutex_unlock(&_mutex);
    }
};
template <typename T> pthread_mutex_t Queue<T>::_mutex = PTHREAD_MUTEX_INITIALIZER;
template <typename T> pthread_cond_t Queue<T>::_cond = PTHREAD_COND_INITIALIZER;

Queue<long> blocking_queue;
volatile bool sentinel = true;

void *produce(void *threadid) {
    long producerId;
    producerId = (long)threadid;
    while (sentinel) {
        blocking_queue.push(producerId);
        usleep(200);
    }
    return NULL;
}

void *consume1(void *threadid) {
    long consumerId;
    consumerId = (long)threadid;
    long producerId;
    while (sentinel) {
        blocking_queue.blocking_pop(producerId);
        cout << "consumer " << consumerId << " consume " << producerId << endl;
        usleep(100);
    }
    return NULL;
}

void *consume2(void *threadid) {
    long consumerId;
    consumerId = (long)threadid;
    long producerId;
    while (sentinel) {
        if (blocking_queue.nonblocking_pop(producerId)) {
            cout << "consumer " << consumerId << " consume " << producerId << endl;
        }
    }
    return NULL;
}

void test1() {
    pthread_t producer_threads[NUM_THREADS];
    pthread_t consumer_threads[NUM_THREADS];
    for (long t = 0; t < NUM_THREADS; t++){
        cout << "In main: creating producer thread " << t << endl;
        pthread_create(&producer_threads[t], NULL, produce, (void *)t);
        cout << "In main: creating consumer thread " << t << endl;
        pthread_create(&consumer_threads[t], NULL, consume1, (void *)t);
    }

}

void test2() {
    pthread_t producer_threads[NUM_THREADS];
    pthread_t consumer_threads[NUM_THREADS];
    for (long t = 0; t < NUM_THREADS; t++){
        cout << "In main: creating producer thread " << t << endl;
        pthread_create(&producer_threads[t], NULL, produce, (void *)t);
        cout << "In main: creating consumer thread " << t << endl;
        pthread_create(&consumer_threads[t], NULL, consume2, (void *)t);
    }
}

int main() {
        test1();
//    test2();
        usleep(1000);
        sentinel = false;
    return 0;
}

