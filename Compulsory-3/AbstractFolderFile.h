#pragma once
#include <string>
#include <iostream>
class AbstractFolderFile
{
private:
	float size;
	std::string name;
	std::string dateOfCreation;


	/// <summary>
	/// Sets date of creation of object
	/// </summary>
	/// <param name="dateOfCreation"></param>
	void setDateOfCreation(std::string dateOfCreation) {
		AbstractFolderFile::dateOfCreation = dateOfCreation;
	}

	/// <summary>
	/// Sets size of object
	/// </summary>
	/// <param name="size"></param>
	void setSize(float size) {
		AbstractFolderFile::size = size;
	}

protected:
	
	/// <summary>
	/// initialises AbstractFolderFile as superclass
	/// </summary>
	/// <param name="size"></param>
	/// <param name="name"></param>
	/// <param name="dateOfCreation"></param>
	AbstractFolderFile(float size, std::string name) {
		setSize(size);
		setName(name);
		setDateOfCreation("temp date");
	}

public:
	/// <summary>
	/// Get size
	/// </summary>
	/// <returns>size</returns>
	virtual float getSize() {
		return size;
	}

	/// <summary>
	/// Get name
	/// </summary>
	/// <returns>name</returns>
	std::string getName() {
		return name;
	}

	/// <summary>
	/// Get date of creation
	/// </summary>
	/// <returns>date of creation</returns>
	std::string getDateOfCreation() {
		return dateOfCreation;
	}

	/// <summary>
	/// Changes name
	/// </summary>
	/// <param name="name"></param>
	virtual void setName(std::string name) {
		AbstractFolderFile::name = name;
	}

	/// <summary>
	/// Get string containing information on object
	/// </summary>
	/// <returns></returns>
	virtual std::string toString() = 0;

	/// <summary>
	/// Prints information on object
	/// </summary>
	void print() {
		std::cout << toString();
	}
};

