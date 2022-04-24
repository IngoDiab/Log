#pragma once
#include <mutex>
#include "File.h"

using namespace std;

class Utils
{
	static mutex mUtilsMutex;
	static const unsigned int mCurrentSizeBuffer = 0;
	static const unsigned int mSizeBuffer = 1024;
	//static const char* mBuffer = (char*) malloc(1024);

public:
	Utils() = delete;

public:
	static void LogText(const char* _text, const char* _formatDate = "%i/%i/%i", const char* _formatTime = "%i:%i:%i");

	static void GetCurrentDate(char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatDate = "%i/%i/%i");
	static void GetCurrentDate(const tm& _timeStruct, char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatDate = "%i/%i/%i");

	static void GetCurrentTime(char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatTime = "%i:%i:%i");
	static void GetCurrentTime(const tm& _timeStruct, char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatTime = "%i:%i:%i");

private:
	static bool WriteInFile(const char* _path, const char* _content, const bool& _replaceCurrentContent = false);
	static tm GetTimeStruct();
};

