#pragma once
#include "AbstractFolderFile.h"
#include "File.h"
#include "Input.h"

class Folder: public AbstractFolderFile
{
private:
	Folder *folders;
	File* files;
	int foldersSize = 0;
	int filesSize = 0;
	int foldersSizeMax = 5;
	int filesSizeMax = 10;

	Folder() : AbstractFolderFile("", 0) {
		folders = NULL;
		files = NULL;
	}

	/// <summary>
	/// Helper function to open new folder
	/// </summary>
	/// <returns>true if success</returns>
	bool openFolder() {
		if (foldersSize == 0) {
			return 0;
		}
		bool isRunning = true;
		std::string name;
		while (isRunning) {
			std::cout << "Type the name of the folder you want to open, or EXIT to go back\n";
			
			std::cin >> name;
			if (name._Equal("EXIT")) {
				isRunning = false;
			}
			else if (hasFolder(name)) {
				isRunning = false;
				getFolder(name).operateFolder();
			}
			else {
				std::cout << "No folder with that name\n";
			}
		}
		return true;
	}

	/// <summary>
	/// Helper function to open new file
	/// </summary>
	/// <returns>true if success</returns>
	bool openFile() {
		if (filesSize == 0) {
			return 0;
		}
		bool isRunning = true;
		std::string name;
		while (isRunning) {
			std::cout << "Type the name of the file you want to open, or EXIT to go back\n";

			std::cin >> name;
			if (name._Equal("EXIT")) {
				isRunning = false;
			}
			else if (hasFile(name)) {
				isRunning = false;
				getFile(name).operateFile();
			}
			else {
				std::cout << "No file with that name\n";
			}
		}
		return true;
	}

	/// <summary>
	/// Helper function to make folder
	/// </summary>
	/// <returns></returns>
	bool makeFolder() {
		if (foldersSize >= foldersSizeMax) {
			return 0;
		}
		bool isRunning = true;
		std::string name;
		while (isRunning) {
			std::cout << "Type the name of the folder you want to make, or EXIT to go back\n";

			std::cin >> name;
			if (name._Equal("EXIT")) {
				isRunning = false;
			}
			else if (!hasFolder(name)) {
				isRunning = false;
				addFolder(name);
			}
			else {
				std::cout << "Folder with name already exists\n";
			}
		}
		return true;
	}

	/// <summary>
	/// Helper function to make file
	/// </summary>
	/// <returns></returns>
	bool makeFile() {

	}

public:
	Folder(std::string name) : AbstractFolderFile(name, 0) {
		//rand() is seeded in main

		float size = (float(rand()) / float((RAND_MAX)) * 100);
		setSize(size);

		//create folders
		folders = new Folder[foldersSizeMax];
		files = new File[filesSizeMax];
	}

	~Folder() {
		delete[] folders;
		delete[] files;
	}

	std::string toString() override{
		std::ostringstream message;

		//stream with folder names and index
		message << "Folders:\n";
		if (foldersSize == 0) {
			message << "NO FOLDERS\n";
		}
		for (int i = 0; i < foldersSize; i++) {
			message << i<< ". Name: " << folders[i].getName() << ". Size: " << folders[i].getSize() << " MB. Created: " << folders[i].getDateOfCreation() << ".\n";
		}

		//stream with file index and information
		message << "\nFiles:\n";
		if (filesSize == 0) {
			message << "NO FILES\n";
		}
		for (int i = 0; i < filesSize; i++) {
			message << i << ". Name: " << files[i].getName() << ". Size: " << files[i].getSize() << " MB. Created: " << files[i].getDateOfCreation() << ".\n";
		}

		//return
		return message.str();
	}

	/// <summary>
	/// Creates a new file if this folder has capacity.
	/// </summary>
	/// <returns>true if succeed, false if failed</returns>
	bool addFile(std::string name) {
		if (filesSize >= filesSizeMax) {
			return false;
		}
		if (hasFile(name)) {
			return false;
		}
		files[filesSize] = File(name);
		filesSize++;
		return true;

	}

	/// <summary>
	/// Creates a new folder if this folder has capacity.
	/// </summary>
	/// <returns>true if succeed, false if failed</returns>
	bool addFolder(std::string name) {
		if (foldersSize >= foldersSizeMax) {
			return false;
		}
		if (hasFolder(name)) {
			return false;
		}
		folders[foldersSize] = Folder(name);
		foldersSize++;
		return true;
	}

	/// <summary>
	/// Get the file on the index.
	/// Use toString() to see index of folders.
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	File getFile(int index) {
		if (!(index >= 0 && index < 5)) {
			std::ostringstream message;
			message << "Index was " << index << ". Array size is " << filesSize << ". Expected between inclusive 0 and exclusive " << filesSize;
			
			throw std::out_of_range(message.str());
		}
		return files[index];
	}

	/// <summary>
	/// Get the file with the name.
	/// throws exception with string "No such name" if the name is not stored.
	/// </summary>
	/// <param name="index"></param>
	/// <returns>file</returns>
	File getFile(std::string name) {
		if (!hasFile(name)) {
			throw std::exception("No such name");
		}
		int index;
		for (int i = 0; i < filesSize; i++) {
			if (name._Equal(files[i].getName())) {
				index = i;
			}
		}
		return files[index];
	}

	/// <summary>
	/// Get the folder with the name.
	/// throws exception with string "No such name" if the name is not stored.
	/// </summary>
	/// <param name="index"></param>
	/// <returns>folder</returns>
	Folder getFolder(std::string name) {
		if (!hasFolder(name)) {
			throw std::exception("No such name");
		}
		int index;
		for (int i = 0; i < foldersSize; i++) {
			if (name._Equal(folders[i].getName())) {
				index = i;
			}
		}
		return folders[index];
	}

	/// <summary>
	/// Get the folder on the index.
	/// Use toString() to see index of folders.
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	Folder getFolder(int index) {
		if (!(index >= 0 && index < 5)) {
			std::ostringstream message;
			message << "Index was " << index << ". Array size is " << foldersSize << ". Expected between inclusive 0 and exclusive " << foldersSize;

			throw std::out_of_range(message.str());
		}
		return folders[index];
	}

	/// <summary>
	/// checks if folder has file name
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	bool hasFile(std::string name) {
		for (int i = 0; i < filesSize; i++) {
			if (name._Equal(files[i].getName())) {
				return 1;
			}
		}
		return 0;
	}

	/// <summary>
	/// checks if folder has folder name
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	bool hasFolder(std::string name) {
		for (int i = 0; i < foldersSize; i++) {
			if (name._Equal(folders[i].getName())) {
				return 1;
			}
		}
		return 0;
	}

	/// <summary>
	/// Gets the stored file with largest size.
	/// 
	/// throws exception with string "Folder has no files" if the folder
	/// holds no files
	/// </summary>
	/// <returns>largest file</returns>
	File getFileLargest() {
		if (filesSize == 0) {
			throw std::exception("Folder has no files");
		}
		int indexLargest = 0;
		for (int i = 0; i < filesSize; i++) {
			if (files[indexLargest].getSize() < files[i].getSize()) {
				indexLargest = i;
			}
		}
		return files[indexLargest];
	}

	/// <summary>
	/// Function to operate files
	/// </summary>
	bool operateFolder() {
		bool isRunning = true;
		int input = 0;
		std::ostringstream commands;
		while (isRunning) {
			//cleaning stream
			commands.str("");
			commands.clear();

			commands << "IN: " << Folder::getName() << std::endl <<
				"Enter integer to perform correspongding action.\n" <<
				"1: ls\n2: cd Folder\n3: cd File\n4: make Folder\n5: Make File\n6: Display largest File\n7: EXIT";
			std::cout << commands.str();
			input = inputInt();

			switch (input) {
			case 1:
				Folder::print();
				break;
			case 2:
				openFolder();
				break;
			case 3:
				openFile();
				break;
			case 4:
				makeFolder();
				break;
			case 5:
				makeFile();
				break;
			case 6:
				Folder::getFileLargest().print();
				break;
			case 7:
				isRunning = false;
				break;
			default:
				std::cout << "Invalid integer";
				break;
			}

		}
	}
};

