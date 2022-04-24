#include <iostream>
#include <time.h>
#include "Utils.h"

using namespace std;

int main()
{
    cout << "Log Multithreading" << endl;
    Utils::LogText("This is a debug log", "%i_%i_%i", "%ih%im%is");
}
