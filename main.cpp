#include <iostream>
#include "linkedlist1.cpp"
#include "book.cpp"
#include "library.cpp"
using namespace std;
// template <typename T>
//  T x;
int main()
{
    int choice;
    library lb;
    fstream file("/Users/fatmaomara/Desktop/C++/tasks/catalogbooks.txt");
    do
    {
        cout << "\t\t\033[1;38;2;120;70;150mWelcome to the Library Management System!" << endl;
        cout << "Please select from the following options:" << endl;
        cout << "1. Book Catalog" << endl;
        cout << "2. Add Book" << endl;
        cout << "3. Remove Book" << endl;
        cout << "4. Search for a Book " << endl;
        cout << "5. Borrow Book" << endl;
        cout << "6. Return Book" << endl;
        cout << "7. Book Statistics" << endl;
        cout << "8. Sort Books" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lb.displaylib();
            break;
        case 2:
        {
            book b1;
            int n;
            cout << "How Many Books Do You Want To Add ? ";
            cin >> n;
            cin.ignore();
            if (!file.is_open())
            {
                cout << "Could not open file." << endl;
                break;
            }
            cout << "Reading ....\n";
            for (int i = 0; i < n; i++)
            {
                file >> b1;
                lb.addbook(b1);
            }
            cout << "Successfully Read !\n";
            break;
        }
        break;
        case 3:
            lb.removebook();
            break;
        case 4:
            lb.searchbook();
            break;
        case 5:
            lb.borrowbook();
            break;
        case 6:
            lb.returnbook();
            break;
        case 7:
            lb.stat();
            break;
        case 8:
            lb.sortedmerge();
            break;
        case 9:
            cout << "Exitting......\n";
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);
    return 0;
}