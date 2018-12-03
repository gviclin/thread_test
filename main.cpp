#include "mainwindow.h"
#include <QApplication>
#include <chrono>
#include <QtDebug>
#include <thread>
#include <mutex>

static const int num_threads = 10;

int total =0;
std::mutex mutex;

void call_from_thread(int tid) {
     qDebug() << "Launched thread " << tid;
    auto start = std::chrono::system_clock::now();

    mutex.lock();
    for (int i=0;i<1000000;i++)
    {

        total++;
    }
    mutex.unlock();

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;

    qDebug() << "End thread " << tid
             << " total : " << total
             << " . duration : "<< diff.count() << " s";

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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

   // MainWindow w;
  //  w.show();

    return a.exec();
}
