#pragma once
#include "AbstractFolderFile.h"
#include <sstream>
#include "Input.h"

class File: public AbstractFolderFile
{

public:
	/// <summary>
	/// DEfault constructor used ONLY by Folder. DO NOT USE
	/// </summary>
	File() : AbstractFolderFile("", 0) {

	}

	File(std::string name, float size) : AbstractFolderFile(name, size) {
	}

	File(std::string name) : AbstractFolderFile(name, 0) {
		//rand() is seeded in main
		
		float size = (float(rand()) / float((RAND_MAX)) * 100);
		setSize(size);
	}

	
	std::string toString(){
		std::ostringstream str;
		str << "name: " << getName() << ".  Size: " << getSize() << " MB.  Date of Creation: " << getDateOfCreation();
	
		return std::string(str.str());
	}

	/// <summary>
	/// Function which enables interfacing the file.
	/// </summary>
	bool operateFile() {
		bool isRunning = true;
		int input = 0;
		std::ostringstream commands;
		while (isRunning) {
			//cleaning stream
			commands.str("");
			commands.clear();

			commands << "---\nIN: " << File::getName() << std::endl <<
				"Enter integer to perform correspongding action.\n" <<
				"1: print\n2: EXIT\n---\n";
			std::cout << commands.str();
			input = inputInt();

			switch (input) {
			case 1:
				print();
				break;
			case 2:
				isRunning = false;
				break;
			default:
				std::cout << "Invalid integer\n";
				break;
			}
		}
		return true;
	}
};

