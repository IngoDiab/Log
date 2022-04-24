#include <iostream>
#include <string>

#include "Utils.h"
#include "Buffer.h"
#include "File.h"

using namespace std;

shared_ptr<Buffer<char>> Utils::mBuffer(new Buffer<char>(1024));

void Utils::LogText(const char* _text, const char* _formatDate, const char* _formatTime)
{
	//lock_guard<mutex> lock(mUtilsMutex);
	//Get time struct
	tm _timeStruct = GetTimeStruct();
	const unsigned int _sizeOutBufferDate = 10;
	const unsigned int _sizeOutBufferTime = 10;

	//Allocate space needed in heap
	char* _bufferDate = (char*) malloc(_sizeOutBufferDate);
	char* _bufferTime = (char*) malloc(_sizeOutBufferTime);

	//Fill buffers
	GetCurrentDate(_timeStruct, _bufferDate, _sizeOutBufferDate, _formatDate);
	GetCurrentTime(_timeStruct, _bufferTime, _sizeOutBufferTime, _formatTime);

	//Display
	//cout << _bufferDate << '|' << _bufferTime << " ==> " << _text << endl;

	const unsigned int _resultSize = _sizeOutBufferDate + _sizeOutBufferTime + 6;
	char* _resultLog = (char*)malloc(_resultSize);

	//Free buffers
	free(_bufferDate);
	free(_bufferTime);
	free(_resultLog);
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

bool Utils::WriteInFile(const char* _path, const char* _content, const bool& _replaceCurrentContent)
{
	ofstream _file;
	if (!File::OpenFile(_file, _path, _replaceCurrentContent)) return false;
	File::WriteInFile(_file, _content);
	File::CloseFile(_file);
	return true;
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
