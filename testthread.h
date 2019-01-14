#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <thread>
#include <mutex>

class TestThread
{

public:
    TestThread();

    void LaunchThreads();
    static void call_from_thread(int tid);

private:
    const int num_threads = 10;
    static int total;
    static std::mutex mutex;

};

#endif // TESTTHREAD_H
