#pragma once
#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <sstream>

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

	

protected:
	
	/// <summary>
	/// initialises AbstractFolderFile as superclass
	/// </summary>
	/// <param name="size"></param>
	/// <param name="name"></param>
	/// <param name="dateOfCreation"></param>
	AbstractFolderFile(std::string name, float size) {
		setSize(size);
		setName(name);

		//source https://stackoverflow.com/a/16358111
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
		auto str = oss.str();

		setDateOfCreation(str);
	}
	/// <summary>
	/// Sets size of object
	/// </summary>
	/// <param name="size"></param>
	void setSize(float size) {
		AbstractFolderFile::size = size;
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

