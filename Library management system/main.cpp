#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Library {
private:
    int bookID;
    string title;
    string author;
    int quantity;

public:
    void addBook() {
        ofstream file("library.txt", ios::app);

        cout << "\nEnter Book ID: ";
        cin >> bookID;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter Quantity: ";
        cin >> quantity;

        file << bookID << "|" << title << "|" << author << "|" << quantity << endl;

        file.close();

        cout << "\nBook Added Successfully!\n";
    }

    void displayBooks() {
        ifstream file("library.txt");

        string line;

        cout << "\n----- Book Records -----\n";

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    void searchBook() {
        ifstream file("library.txt");

        int searchID;
        bool found = false;

        cout << "\nEnter Book ID to Search: ";
        cin >> searchID;

        while (file >> bookID) {
            file.ignore();

            getline(file, title, '|');
            getline(file, author, '|');
            file >> quantity;

            if (bookID == searchID) {
                cout << "\nBook Found!\n";
                cout << "Book ID : " << bookID << endl;
                cout << "Title   : " << title << endl;
                cout << "Author  : " << author << endl;
                cout << "Quantity: " << quantity << endl;

                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nBook Not Found!\n";
        }

        file.close();
    }
};

int main() {
    Library lib;

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                lib.searchBook();
                break;

            case 4:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;s
}