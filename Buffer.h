#pragma once

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
	return false;
}

template<class BufferedType>
inline void Buffer<BufferedType>::WriteInBuffer(const char* _content)
{
	sprintf_s(mBuffer, mMaxSizeBuffer * sizeof(BufferedType), "%s", _content);
}

template<class BufferedType>
inline void Buffer<BufferedType>::EmptyBufferInFile(const char* _path)
{
	if (!mBuffer || IsBufferEmpty()) return;
	Utils::WriteInFile(_path, mBuffer);
}
