#include <iostream>
#include <time.h>
#include "Utils.h"
#include "Buffer.h"

using namespace std;

int main()
{
    Buffer<char>* _bufferLog = new Buffer<char>(1024);
    cout << "Log Multithreading" << endl;
    cout << sizeof("pppp") << endl; //5 = 4 + end character
    Utils::LogText("This is a debug log", "%i_%i_%i", "%ih%im%is");
    delete _bufferLog;
}
