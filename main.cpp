#include <iostream>
#include <time.h>
#include <vector>

#include <thread>
#include "Utils.h"
#include "Buffer.h" 

#define FORMAT_DATE "%i/%i/%i"
#define FORMAT_TIME "%i:%i:%i"
#define FORMAT_RESULT "[%s-%s]Log : \"%s %i\"\n"
#define NB_THREADS 1604

using namespace std;

void LogSingleThreading();
void LogMultiThreading();

int main()
{
    //LogSingleThreading();
    LogMultiThreading();
}

void LogSingleThreading()
{
    cout << "========================================================================" << endl;
    cout << "                              Log Singlethreading                       " << endl;
    cout << "========================================================================" << endl;

    for (int i = 0; i < NB_THREADS; ++i)
        Utils::LogText(i, "This is a log from single thread", FORMAT_DATE, FORMAT_TIME, FORMAT_RESULT);

    cout << "========================================================================" << endl;
    cout << "                            End Log Singlethreading                     " << endl;
    cout << "========================================================================" << endl;
}

void LogMultiThreading()
{
    cout << "========================================================================" << endl;
    cout << "                              Log Multithreading                        " << endl;
    cout << "========================================================================" << endl;

    vector<thread> _threads;

    for (int i = 0; i < NB_THREADS; ++i)
        _threads.push_back(thread(&Utils::LogText,i, "This is a log from multi thread", FORMAT_DATE, FORMAT_TIME, FORMAT_RESULT));

    for (int i = 0; i < _threads.size(); ++i)
        _threads.at(i).join();

    cout << "========================================================================" << endl;
    cout << "                            End Log Multithreading                      " << endl;
    cout << "========================================================================" << endl;
}


