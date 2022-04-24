#pragma once
#include <iostream>
#include "Utils.h"

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
	bool IsAboutToBeFull(const char* _content) const;

	void DisplayBufferContent() const;
	void GetCurrentSizeFill() const;
	void WriteInBuffer(const char* _content);
	void EmptyBufferInFile(const char* _path);
};

template<class BufferedType>
inline Buffer<BufferedType>::Buffer(const unsigned int& _maxSizeBuffer) : mMaxSizeBuffer(_maxSizeBuffer)
{
	mBuffer = (BufferedType*)malloc(sizeof(BufferedType) * _maxSizeBuffer);
	mCurrentSizeBuffer = 0;
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
	return mCurrentSizeBuffer + strlen(_content)+1 > mMaxSizeBuffer;
}

template<class BufferedType>
inline void Buffer<BufferedType>::DisplayBufferContent() const
{
	cout << mBuffer << endl;
}

template<class BufferedType>
inline void Buffer<BufferedType>::GetCurrentSizeFill() const
{
	return mCurrentSizeBuffer;
}

template<class BufferedType>
inline void Buffer<BufferedType>::WriteInBuffer(const char* _content)
{
	if (IsAboutToBeFull(_content)) EmptyBufferInFile("test.txt");
	sprintf_s(mBuffer, mMaxSizeBuffer * sizeof(BufferedType), "%s", _content);
	mCurrentSizeBuffer += strlen(_content) + 1;
}

template<class BufferedType>
inline void Buffer<BufferedType>::EmptyBufferInFile(const char* _path)
{
	if (!mBuffer || IsBufferEmpty()) return;
	Utils::WriteInFile(_path, mBuffer);
	mCurrentSizeBuffer = 0;
}
