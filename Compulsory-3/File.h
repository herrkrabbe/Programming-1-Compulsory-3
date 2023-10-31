#pragma once
#include "AbstractFolderFile.h"
#include <sstream>

class File: public AbstractFolderFile
{
public:
	File(std::string name, float size) : AbstractFolderFile(name, size) {
	}

	File(std::string name) : AbstractFolderFile(name, 0) {
		//rand() is seeded in main
		
		float size = (float(rand()) / float((RAND_MAX)) * 100);
		setSize(size);
	}

	//TODO
	std::string toString(){
		std::ostringstream str;
		str << "name: " << getName() << ".  Size: " << getSize() << " MB.  Date of Creation: " << getDateOfCreation();
	
		return std::string(str.str());
	}
};

