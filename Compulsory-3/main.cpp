
#include "File.h"
#include "Folder.h"

void main() {
	srand((unsigned int)time(NULL));
	File foo1 = File("Test");
	File foo2 = File("Test2");
	
	Folder fold = Folder("Folder1");
	
	File foo3 = File("Test3");
	File foo4 = File("Test4", 5);
	File foo5 = File("Test4", 5);
	
	std::cout << foo1.toString() << "\n";
	std::cout << foo2.toString() << "\n";
	std::cout << foo3.toString() << "\n";
	std::cout << foo4.toString() << "\n";
	std::cout << foo5.toString() << "\n";

	fold.addFile("File 1");
	fold.addFile("File 2");

	fold.addFolder("Folder 1");

	fold.print();

	fold.getFileLargest().print();


	
}