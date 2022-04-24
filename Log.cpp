#include <iostream>
#include <time.h>
#include "Utils.h"
#include "Buffer.h"

using namespace std;

int main()
{
    cout << "Log Multithreading" << endl;
    cout << sizeof("pppp") << endl; //5 = 4 + end character
    Utils::LogText("This is a debug log", "%i_%i_%i", "%ih%im%is");
    Utils::LogText("This is a second debug log", "%i_%i_%i", "%ih%im%is");
    Utils::WriteInFile("test.txt", "ARABE");
}
