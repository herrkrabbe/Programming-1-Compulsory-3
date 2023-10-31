#pragma once
#include "AbstractFolderFile.h"
#include "File.h"

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
	// Inherited via AbstractFolderFile
	//TODO
	std::string toString() override{
		return std::string();
	}

	/// <summary>
	/// Creates a new file if this folder has capacity.
	/// </summary>
	/// <returns>true if succeed, false if failed</returns>
	bool newFile(std::string name) {
		if (filesSize >= filesSizeMax) {
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
	bool newFolder(std::string name) {
		if (foldersSize >= foldersSizeMax) {
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
		//TODO
	}

	/// <summary>
	/// Get the folder on the index.
	/// Use toString() to see index of folders.
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	Folder getFolder(int index) {
		//TODO
	}
};

