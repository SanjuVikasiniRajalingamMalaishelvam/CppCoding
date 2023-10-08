// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include <fstream>

// Add more standard header files as required
// #include <string>
#include "Book.h"
#include "TextBook.h"
#include "Novel.h"
#include "Books.h"
#include "LibraryDB.h"


using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here
	Book *novel = new Novel("WingsofFire", "APJAbdulKalam", "Biography");
	Book *text = new TextBook("APT", "Prof Lipp", "Masters");


	cout << *novel <<endl;
	cout << *text <<endl;

	Books *booksPtr = new Books();


	User user1(User::getNextID(),"sanju", "darmstadt");

	LibraryDB libObj(*booksPtr);
	libObj.addUser(&user1);
	libObj.addBook("Motivation", novel);
	libObj.addBook("Studies", text);
	libObj.assignBook(1, "Motivation", "WingsofFire", "APJAbdulKalam");


	libObj.print();

	fstream file;
	file.open("data.txt");

//	novel->write(file);
//	text->write(file);

	booksPtr->write(file);






	return 0;
}
