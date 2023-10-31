#pragma once
#include "AbstractFolderFile.h"

class Folder: public AbstractFolderFile
{
	// Inherited via AbstractFolderFile
	std::string toString() override{
		return std::string();
	}
};

