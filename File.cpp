#include "File.h"

bool File::OpenFile(ofstream& _outputFile, const char* _path, const bool& _replaceCurrentContent)
{
	_replaceCurrentContent ? _outputFile.open(_path) : _outputFile.open(_path, ios::app);
	return _outputFile.is_open();
}

void File::WriteInFile(ofstream& _outputFile, const char* _content)
{
	if (!_outputFile.is_open()) return;
	_outputFile << _content << endl;
}

void File::CloseFile(ofstream& _outputFile)
{
	_outputFile.close();
}
