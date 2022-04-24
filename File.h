#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class File
{
public:
	File() = delete;

public:
	static bool OpenFile(ofstream& _outputFile, const char* _path, const bool& _replaceCurrentContent = false);
	static void WriteInFile(ofstream& _outputFile, const char* _content);
	static void CloseFile(ofstream& _outputFile);
};

