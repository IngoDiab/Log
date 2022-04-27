#include "File.h"
#include <direct.h>

bool File::OpenFile(ofstream& _outputFile, const char* _path, const bool& _replaceCurrentContent)
{
	_replaceCurrentContent ? _outputFile.open(_path) : _outputFile.open(_path, ios::app);
	return _outputFile.is_open();
}

void File::WriteInFile(const char* _path, const char* _content, const bool& _replaceCurrentContent)
{
	/*const unsigned int _sizeTemp = (strlen(_content) + 1) * sizeof(char);
	char* _temp = (char*)malloc(_sizeTemp);
	strncpy_s(_temp, _sizeTemp, _content, strlen(_content));
	char* _tempPoint = strtok_s(_temp, "/");
	cout << _tempPoint << endl;*/

	ofstream _file;
	if (!File::OpenFile(_file, _path, _replaceCurrentContent)) return;

	//Allocate a buffer and copy _content to delete last '\n' from _content before pasting it in a file (avoid inserting a new line to the file after emptying buffer in it)
	//const unsigned int _sizeCopy = (strlen(_content)) * sizeof(char);
	//char* _contentToPasteInFile = (char*)malloc(_sizeCopy);
	//strncpy_s(_contentToPasteInFile, _sizeCopy, _content, strlen(_content) - 1);

	//Paste content in file
	_file << _content;

	//Free close file
	File::CloseFile(_file);
}

void File::CloseFile(ofstream& _outputFile)
{
	_outputFile.close();
}