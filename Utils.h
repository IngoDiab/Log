#pragma once

#include <ctime>
#include <memory>
#include <mutex>

using namespace std;

#define SIZE_BUFFER 1024

template<class>
class Buffer;

class Utils
{
	static shared_ptr<Buffer<char>> mBuffer;
	static mutex mMutex;

public:
	Utils() = delete;

public:
	static void LogText(const unsigned int& _indexThread, const char* _text, const char* _formatDate = "%i/%i/%i", const char* _formatTime = "%i:%i:%i");

	static void GetCurrentDate(char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatDate = "%i/%i/%i");
	static void GetCurrentDate(const tm& _timeStruct, char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatDate = "%i/%i/%i");

	static void GetCurrentTime(char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatTime = "%i:%i:%i");
	static void GetCurrentTime(const tm& _timeStruct, char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatTime = "%i:%i:%i");

	static void WaitForXMilliseconds(int ms);
	static void WaitForXMillisecondsMaximum(int ms);

private:
	static tm GetTimeStruct();
};

