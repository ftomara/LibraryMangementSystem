#include <iomanip>
#include <iostream>
#include "linkedlist1.cpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include <cstring>
using namespace std;
#ifndef BOOK_H
#define BOOK_H

class book
{

private:
    string title;
    string author;
    string ISBN;
    string genre;
    bool av;
    bool br;

public:
    // friend class linkedlist1<book>;
    friend class library;
    friend ostream &operator<<(ostream &out, book &b1);
    friend istream &operator>>(istream &in, book &b1);
    book() : av(true), br(false) {}
    // book(string s){
    //    title = ISBN = s;
    // }
    book &operator=(book &other)
    {
        this->author = other.author;
        this->genre = other.genre;
        this->ISBN = other.ISBN;
        this->title = other.title;
        return *this;
    }
    // bool operator==(book &other)
    // {
    //     if (ISBN == other.ISBN || title == other.title)
    //         return true;
    //     else
    //         return false;
    // }
    bool operator==(string &key)
    {

        return (title == key || ISBN == key);
    }
    bool operator!=(book &other)
    {
        if (ISBN != other.ISBN)
            return true;
        else
            return false;
    }
    bool operator<=(book &other)
    {
        if (title <= other.title)
            return true;
        else
            return false;
    }
};

ostream &operator<<(ostream &out, book &b1)
{
    const int fieldWidth = 23;

    out << "Title: " << setw(fieldWidth) << left << b1.title << "|";
    out << "Author: " << setw(fieldWidth) << left << b1.author << "|";
    out << "Genre: " << setw(fieldWidth) << left << b1.genre << "|";
    out << "ISBN: " << setw(fieldWidth) << left << b1.ISBN << "|";

    if (out)
    {
        std::ios_base::fmtflags flags = out.flags();
        out << std::boolalpha;

        if (b1.av == true)
            out << "Available Status: " << setw(fieldWidth) << left << "\033[1;32mAV\033[1;38;2;120;70;150m | ";
        else
            // out << "Available Status: " << setw(fieldWidth) << left << "\033[1;31mNOT AV\033[1;38;2;120;70;150m | ";
            out << "Available Status: " << setw(fieldWidth) << left << "\033[1;31mBorrowed\033[1;38;2;120;70;150m |";

        // if (b1.br == true)
        // else
        //     out << "\033[1;31mNot Borrowed\033[1;38;2;120;70;150m |";

        out.flags(flags);
    }
    return out;
}
std::istream &operator>>(std::istream &in, book &b)
{

    getline(in, b.title, ',');
    getline(in, b.author, ',');
    getline(in, b.genre, ',');
    getline(in, b.ISBN, ',');
    std::string temp;
    if (getline(in, temp, ','))
    {

        b.av = (temp == "true");
    }
    if (getline(in, temp))
    {
        b.br = (temp == "true");
    }

    return in;
}
// istream &operator>>(istream &in, book &b1)
// {

//     in >> b1.av;
//     in >> b1.br;

//     cout << "Successfully Read !\n";
//     return in;
// // fstream file;
// file.open("/Users/fatmaomara/Desktop/DR.Mahmoud/tasks/catalogbooks.txt");

// if (!file.is_open())
// {
//     cout << "Could not open file." << endl;
//     return in;
// }
// cout << "Reading From File ....\n";

// while (file >> b1.br)
// {
//     getline(file, b1.title, ',');
//     getline(file, b1.author, ',');
//     getline(file, b1.genre, ',');
//     getline(file, b1.ISBN, ',');
//     file >> b1.av;
// }

// file.close();
// return in;

// cout << "Enter your book info: \n";
// cout << "Title: ";
// in.ignore();
// getline(in, b1.title);
// cout << "Author: ";
// // in.ignore();
// getline(in, b1.author);
// cout << "ISBN: ";
// // in.ignore();
// getline(in, b1.ISBN);
// cout << "Genre: ";
// // in.ignore();
// getline(in, b1.genre);
// cout << "Available Status (0, 1): ";
// in >> b1.av;
// cout << "Borrowed Status (0, 1): ";
// in >> b1.br;
// return in;
//}
#endif
