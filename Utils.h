#pragma once
#include <mutex>

using namespace std;

class Utils
{
	//mutex mUtilsMutex;
	char* mBuffer = nullptr;
	unsigned int mCurrentSizeBuffer = 0;
	unsigned int mSizeBuffer = 1024;

public:
	static void LogText(const char* _text, const char* _formatDate = "%i/%i/%i", const char* _formatTime = "%i:%i:%i");

	static void GetCurrentDate(char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatDate = "%i/%i/%i");
	static void GetCurrentDate(const tm& _timeStruct, char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatDate = "%i/%i/%i");

	static void GetCurrentTime(char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatTime = "%i:%i:%i");
	static void GetCurrentTime(const tm& _timeStruct, char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatTime = "%i:%i:%i");

private:
	static tm GetTimeStruct();
};

