#include <iostream>
#include <string>
#include <thread>

#include "Utils.h"
#include "Buffer.h"
#include "File.h"

using namespace std;

shared_ptr<Buffer<char>> Utils::mBuffer(new Buffer<char>(SIZE_BUFFER));
mutex Utils::mMutex;

void Utils::LogText(const unsigned int& _indexThread, const char* _text, const char* _formatDate, const char* _formatTime, const char* _formatResult)
{
	//Get time struct
	tm _timeStruct = GetTimeStruct();
	const unsigned int _sizeOutBufferDate = strlen(_formatDate) + 2;
	const unsigned int _sizeOutBufferTime = strlen(_formatTime) + 1;

	//Allocate space needed in heap
	char* _bufferDate = (char*) malloc(_sizeOutBufferDate);
	char* _bufferTime = (char*) malloc(_sizeOutBufferTime);

	//Fill buffers
	GetCurrentDate(_timeStruct, _bufferDate, _sizeOutBufferDate, _formatDate);
	GetCurrentTime(_timeStruct, _bufferTime, _sizeOutBufferTime, _formatTime);
	//Buffers have string content + end string char

	{
		lock_guard<mutex> lock(mMutex);

		//Fill result
		const unsigned int _resultSize = strlen(_bufferDate) + strlen(_bufferTime) + strlen(_text) + strlen(_formatResult); //nb char buffer Date + nb char buffer Time + nb char buffer _text + (10 = 9 format + 1 end char)
		char* _resultBuffer = (char*)malloc(_resultSize);
		sprintf_s(_resultBuffer, _resultSize, _formatResult, _bufferDate, _bufferTime, _text, _indexThread);
		//Result buffer has string content + \n + end string char (but there's no more end char after date/time)

		WaitForXMilliseconds(1000);

		//Display log
		cout << _resultBuffer;

		//Write _resultBuffer in general buffer
		mBuffer->WriteInBuffer(_resultBuffer);

		free(_resultBuffer);
	}

	//Free buffers
	free(_bufferDate);
	free(_bufferTime);
}

void Utils::GetCurrentDate(char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatDate)
{
	tm _timeStruct = GetTimeStruct();
	sprintf_s(_bufferOut, _sizeBuffer, _formatDate, _timeStruct.tm_mday, _timeStruct.tm_mon+1, _timeStruct.tm_year+1900);
}

void Utils::GetCurrentDate(const tm& _timeStruct, char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatDate)
{
	sprintf_s(_bufferOut, _sizeBuffer, _formatDate, _timeStruct.tm_mday, _timeStruct.tm_mon+1, _timeStruct.tm_year+1900);
}

void Utils::GetCurrentTime(char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatTime)
{
	tm _timeStruct = GetTimeStruct();
	sprintf_s(_bufferOut, _sizeBuffer, _formatTime, _timeStruct.tm_hour, _timeStruct.tm_min, _timeStruct.tm_sec);
}

void Utils::GetCurrentTime(const tm& _timeStruct, char* _bufferOut, const unsigned int _sizeBuffer, const char* _formatTime)
{
	sprintf_s(_bufferOut, _sizeBuffer, _formatTime, _timeStruct.tm_hour, _timeStruct.tm_min, _timeStruct.tm_sec);
}

void Utils::WaitForXMilliseconds(int ms)
{
	this_thread::sleep_for(chrono::milliseconds(ms));
}

void Utils::WaitForXMillisecondsMaximum(int ms)
{
	// simulation d'une op�ration 'lente' (attente de 0 � ms millisecondes)
	int wait = rand() % ms;
	WaitForXMilliseconds(wait);
}

tm Utils::GetTimeStruct()
{
	//Get time in a local variable
	time_t _time;
	time(&_time);

	tm buffer;
	localtime_s(&buffer, &_time);

	return buffer;
}
