#include "LibraryBook.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>


int main()
{

    string str1, str2, str3, theISBN;
    vector <LibraryBook> books;
    bool checkedOut;

    ifstream inFile;
    inFile.open("books.txt");
    if (!inFile.is_open()) {
        cout << "File is not open" << endl;
        return 1;
    }




    while (inFile.good()) {

        getline(inFile, str1);
        getline(inFile, str2);
        getline(inFile, str3);

        if (inFile.eof()) {
            break;
        }

        LibraryBook myBook(str1, str2, str3);

        books.push_back(myBook);

    }

    ifstream inFile2;
    inFile2.open("isbns.txt");
    if (!inFile2.is_open()) {
        cout << "File is not open" << endl;
        return 1;
    }

    while (inFile2.good()) {

        inFile2 >> theISBN;

        if (inFile2.eof()) {
            break;
        }

        for (int i = 0; i < books.size(); i++) {

            string num = books.at(i).getISBN();

            if (num == theISBN) {

                checkedOut = books.at(i).isCheckedOut();

                if (checkedOut) {
                    books.at(i).checkIn();

                }

                if (!checkedOut) {
                    books.at(i).checkOut();

                }
            }
        }
    }



    ofstream fout("checkedout.txt");
    fout << "Books checked out:" << endl;
    fout << "-------------------------" << endl << endl << endl;
    fout << "Title   " << "Author   " << "ISBN" << endl << endl;

    for (int i = 0; i < books.size(); i++) {

        bool j = books.at(i).isCheckedOut();

        if (j) {

            fout << books.at(i).getTitle() << " //  " << books.at(i).getAuthor() << " //  " << books.at(i).getISBN() << endl << endl;

        }
    }


    inFile.close();
    inFile2.close();



    cout << "Below is the file report(checkedout.txt):" << endl << endl << endl;

    ifstream inFile3;
    inFile3.open("checkedout.txt");
    if (!inFile3.is_open()) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    string line;
    while (inFile3.good()) {

        getline(inFile3, line);

        if (inFile3.eof()) {
            break;
        }

        cout << line << endl;

    }

}