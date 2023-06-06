#pragma once

#include "railway.h"
class File
{
public:
	void writeToFile(const Railway& railway, const std::string& filename);
	bool readFromFile(Railway& railway, const std::string& filename);

};