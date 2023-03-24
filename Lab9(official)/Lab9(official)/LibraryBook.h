#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class LibraryBook {

private:
	string title;
	string author;
	string ISBN;
	bool checkedOut;

public:
	LibraryBook();                                        //constructors
	LibraryBook(string t, string a, string num);

	string getTitle() { return title; }
	string getAuthor() { return author; }             //getters
	string getISBN() { return ISBN; }
	bool isCheckedOut() { return checkedOut; }

	void checkOut() { checkedOut = true; }
	void checkIn() { checkedOut = false; }         //setters

	void print();            //print

};