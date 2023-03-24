#include "LibraryBook.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

LibraryBook::LibraryBook() {
	title = " ";
	author = " ";
	ISBN = " ";
	checkedOut = false;
}

LibraryBook::LibraryBook(string t, string a, string num) {
	title = t;
	author = a;
	ISBN = num;
	checkedOut = false;
}

void LibraryBook::print() {
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "ISBN: " << ISBN << endl;
}