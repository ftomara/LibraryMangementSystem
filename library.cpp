#include <iostream>
using namespace std;
#include "node.cpp"
#include "linkedlist1.cpp"
#include "book.cpp"
#include "container.cpp"
// #include "bookclass.cpp"
#ifndef LIBRARY_H
#define LIBRARY_H
class library
{
private:
    container<book> catalog;
    int counter;
    int notav;

public:
    library()
    {
        counter = 0;
        notav = 0;
    }
    void addbook(book &b1)
    {

        catalog.Add(b1);
        counter++;
    }
    void removebook()
    {
        if (counter == 0)
        {
            cout << "There Is No Books Yet! \n";
            return;
        }
        string s;
        cout << "Enter Book's ISBN or Title To Delete : ";
        cin.ignore();
        getline(cin, s);
        // book temp(s);
        catalog.DeleteVal(s);
        cout<<"Book Removed  Successfully\n";
        counter--;
    }
    void searchbook()
    {
        if (counter == 0)
        {
            cout << "There Is No Books Yet! \n";
            return;
        }
        string s;
        cout << "Enter Book's ISBN or Title To  Search For : ";
        cin.ignore();
        getline(cin, s);
        // book temp(s);
        if (catalog.SearchsVal(s) != nullptr)
        {
            cout << "Book Found: \n";
            catalog.Display(catalog.SearchsVal(s));
        }
        else
            cout << "Book Not Found ! \n";
    }
    void borrowbook()
    {
        if (counter == 0)
        {
            cout << "There Is No Books Yet! \n";
            return;
        }
        string s;
        cout << "Enter Book's ISBN or Title To Borrow : ";
        cin.ignore();
        getline(cin, s);
        // book temp(s);
        if (catalog.SearchsVal(s))
        {
            node<book> *p = catalog.SearchsVal(s);
            if (p->data.av == 1)
            {
                p->data.av = 0;
                p->data.br = 1;
                notav++;
                cout << "Book Borrowed Successfully\n";
            }
            else
            {
                cout << "Book Isn't AV \n";
                return;
            }
        }
         else
            cout << "Book Not Found ! \n";

    }
    void returnbook()
    {
        if (counter == 0)
        {
            cout << "There Is No Books Yet! \n";
            return;
        }
        string s;
        cout << "Enter Book's ISBN or Title To Borrow : ";
        cin.ignore();
        getline(cin, s);
        // book temp(s);
        if (catalog.SearchsVal(s))
        {
            node<book> *p = catalog.SearchsVal(s);
            if (p->data.br == 1)
            {
                p->data.av = 1;
                p->data.br = 0;
                notav--;
                cout << "Book Returned Successfully\n";
            }
            else
            {
                cout << "Book Isn't Borrowed \n";
                return;
            }
        }
         else
            cout << "Book Not Found ! \n";
    }
    void stat()
    {
        if (counter == 0)
        {
            cout << "There Is No Books Yet! \n";
            return;
        }
        cout << "Total Books : " << counter << "\n";
        cout << "Book Borrowed : " << notav << "\n";
        cout << "Avilable Books : " << counter - notav << "\n";
    }
    void displaylib()
    {
        if (counter == 0)
            cout << "There Is No Books Yet! \n";
        else
        {
            cout << "Here is your Books' Catalog : \n";
            catalog.Display();
        }
    }
    void sortedmerge()
    {
        catalog.Sort();
        cout << "Library Sorted Sccessfully\n";
    }
    ~library()
    {
    }
};
#endif

//}
//  book b1;
//  int n;
//  cout << "How Many Books Do You Want To Add ? ";
//  cin >> n;
//  // cin >> b1;
//  //  catalog.insertfirst(b1);
//  for (int i = 0; i < n; i++)
//  {
//      cin >> b1;
//      catalog.insertlast(b1);
//      counter++;
//  }
// void sortedmerge()
// {
//     node<book> *p = catalog.mergeSort(catalog.head);
//     catalog.head = p;
//     cout << "Library Sorted Sccessfully\n";
// }