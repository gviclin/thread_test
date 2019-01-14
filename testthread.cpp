#include "testthread.h"
#include <chrono>
#include <QtDebug>

std::mutex TestThread::mutex;
int TestThread::total = 0;

TestThread::TestThread()
{
    //default constructor
}

void TestThread::call_from_thread(int tid) {
    qDebug() << "Launched thread " << tid;
    auto start = std::chrono::system_clock::now();
    mutex.lock();
    for (int i=0;i<1000000;i++)
    {

        total++;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;

    qDebug() << "End thread " << tid
             << " total : " << total
             << " . duration : "<< diff.count() << " s";

    mutex.unlock();

}

void TestThread::LaunchThreads()
{
    std::vector<std::thread> vectorThread;

    //Launch a group of threads
    for (int i = 0; i < num_threads; ++i)
    {
        vectorThread.push_back(std::thread(call_from_thread,i));
    }

    qDebug() << "Launched from the main\n";

    //std::this_thread::sleep_for(std::chrono::seconds(1));

    //Join the threads with the main thread
    for (auto& th : vectorThread)
    {
        th.join();
    }
    qDebug() << "Finished "
             << " total : " << total;
}
