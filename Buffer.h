#pragma once
#include <iostream>
#include <mutex>
#include "Utils.h"
#include "File.h"

#define PATH_SAVELOG "Logs_Saved.txt"

template <class BufferedType>
class Buffer
{
	BufferedType* mBuffer = nullptr;
	unsigned int mMaxSizeBuffer = 1024;
	unsigned int mCurrentSizeBuffer = 0;

public:
	Buffer(const unsigned int& _maxSizeBuffer);
	~Buffer();

public:
	bool IsBufferEmpty() const;
	bool IsBufferFull() const;

	void DisplayBufferContent() const;
	void GetCurrentSizeFill() const;
	void WriteInBuffer(const char* _content);
	void EmptyBufferInFile(const char* _path);
	void CleanBuffer();

private:
	bool IsAboutToBeFull(const char* _content) const;
	bool ExceedBuffer(const char* _content) const;
};

template<class BufferedType>
inline Buffer<BufferedType>::Buffer(const unsigned int& _maxSizeBuffer) : mMaxSizeBuffer(_maxSizeBuffer)
{
	CleanBuffer();
}

template<class BufferedType>
inline Buffer<BufferedType>::~Buffer()
{
	free(mBuffer);
}

template<class BufferedType>
inline bool Buffer<BufferedType>::IsBufferEmpty() const
{
	return mCurrentSizeBuffer == 0 && !IsBufferFull();
}

template<class BufferedType>
inline bool Buffer<BufferedType>::IsBufferFull() const
{
	return mCurrentSizeBuffer == mMaxSizeBuffer;
}

template<class BufferedType>
inline bool Buffer<BufferedType>::IsAboutToBeFull(const char* _content) const
{
	//Check if size of _content (= sentence + \n) + end char + mCurrentSizeBuffer exceed mMaxSizeBuffer
	return mCurrentSizeBuffer + strlen(_content) + 1 > mMaxSizeBuffer;
}

template<class BufferedType>
inline bool Buffer<BufferedType>::ExceedBuffer(const char* _content) const
{
	//Check if size of _content (= sentence + \n) + end char + mCurrentSizeBuffer exceed mMaxSizeBuffer
	return strlen(_content)+1 > mMaxSizeBuffer;
}

template<class BufferedType>
inline void Buffer<BufferedType>::DisplayBufferContent() const
{
	if (IsBufferEmpty())return;
	cout << mBuffer;
}

template<class BufferedType>
inline void Buffer<BufferedType>::GetCurrentSizeFill() const
{
	return mCurrentSizeBuffer;
}

template<class BufferedType>
inline void Buffer<BufferedType>::WriteInBuffer(const char* _content)
{

	//If the content exceed buffer's capacity, we empty it in a file
	if (IsAboutToBeFull(_content)) EmptyBufferInFile(PATH_SAVELOG);

	//Check if buffer can receive content
	if (ExceedBuffer(_content)) 
	{
		Utils::WaitForXMilliseconds(2000);
		File::WriteInFile(PATH_SAVELOG, _content);
		return;
	}
	Utils::WaitForXMilliseconds(1000);
	//Copy _content at the end of buffer (if the buffer is already fill, the first char of _content override the end char of the buffer and set it at the end after _content has been added)
	mCurrentSizeBuffer += sprintf_s(mBuffer + mCurrentSizeBuffer, mMaxSizeBuffer * sizeof(BufferedType) - mCurrentSizeBuffer, "%s", _content);
}

template<class BufferedType>
inline void Buffer<BufferedType>::EmptyBufferInFile(const char* _path)
{
	if (!mBuffer || IsBufferEmpty()) return;
	File::WriteInFile(_path, mBuffer);
	CleanBuffer();
}

template<class BufferedType>
inline void Buffer<BufferedType>::CleanBuffer()
{
	if (mBuffer) free(mBuffer);
	mBuffer = (BufferedType*)malloc(sizeof(BufferedType) * mMaxSizeBuffer);
	mCurrentSizeBuffer = 0;
}
