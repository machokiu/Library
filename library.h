//
// Created by Yusuf Pisan on 3/26/18.
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library {
  // display all books in library
  friend ostream &operator<<(ostream &Out, const Library &Lib);

public:
  // constructor with default name
  explicit Library(const string &Name);

  // destructor
  virtual ~Library();

  // add a new book
  // return true if successful, false if
  // book already in library
  bool addBook(const string &BookName);

  // remove a book
  // return true if successfully removed
  // false if book not in library
  bool removeBook(const string &BookName);

  // list all books
  void listAllBooks() const;


  // true if book found in library
  bool isInLibrary(const string &BookName) const;

  

private:
  // max book is 100
  static const int MAX = 100;

  // find the book
  int findBook(const string& BookName) const;

  // keep track the number of book in library
  int NumberOfBooks = 0;

  //Array of the book
  string Books[MAX];

  //name of library
  string Name;

  

 };

#endif  // ASS1_LIBRARY_H
