//
// Created by Marci Ma on 09/29/2019.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
#include <iostream>

// constructor with default name
Library::Library(const string &Name) {
	cout << "Library " << Name << " created" << endl;
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
bool Library::isInLibrary(const string &BookName) const {
	return findBook(BookName) != -1;
}
// find the index of the book
int Library::findBook(const string& BookName) const {
    for (int I = 0; I < NumberOfBooks; I++) {
        if (Books[I] == BookName) {
            return I;
        }
    }
    return -1;
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName) {
  if(findBook(BookName) == -1){
	Books[NumberOfBooks] = BookName;
	NumberOfBooks++;
	return true;
  }
  return false;
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName) {
	int I = findBook(BookName);
	if (I == -1) {
		return false;
	}
	else {
		Books[I] = Books[NumberOfBooks - 1];
		NumberOfBooks--;
	}
  return true;
}

// list all books
void Library::listAllBooks() const {
	cout << "Books in " << Name << "are: " << endl;
	for (int I = 0; I < NumberOfBooks; ++I) {
		cout << Books[I] << endl;
	}
}


ostream &operator<<(ostream &Out, const Library &Lib) {
  Out << "Books in " << Lib.Name << "are: " << endl;
  for (int I = 0; I < Lib.NumberOfBooks; ++I) {
	  Out << Lib.Books[I] << endl;
  }
  return Out;
}
