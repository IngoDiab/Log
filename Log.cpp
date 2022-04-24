#include <iostream>
#include <time.h>
#include "Utils.h"
#include "Buffer.h" 

#define FORMAT_DATE "%i/%i/%i"
#define FORMAT_TIME "%i+%i+%i"

using namespace std;

void LogMultiThreading();

int main()
{
    LogMultiThreading();
}

void LogMultiThreading()
{
    cout << "========================================================================" << endl;
    cout << "                              Log Multithreading                        " << endl;
    cout << "========================================================================" << endl << endl;

    Utils::LogText("This is a 1st debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 2nd debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 3rd debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 4th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 5th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 6th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 7th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 8th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 9th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 10th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 11th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 12th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 13th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 14th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 15th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 16th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 17th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 18th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is a 19th debug log", FORMAT_DATE, FORMAT_TIME);
    Utils::LogText("This is the log after cleaning up buffer 'cause buffer's been override", FORMAT_DATE, FORMAT_TIME);

    Utils::DisplayBuffer();

    cout << "========================================================================" << endl;
    cout << "                            End Log Multithreading                      " << endl;
    cout << "========================================================================" << endl;
}
