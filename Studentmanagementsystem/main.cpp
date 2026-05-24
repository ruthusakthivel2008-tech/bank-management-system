#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;

    void addStudent() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;

        ofstream file("Students.txt", ios::app);
        file << id << "," << name << "," << marks << endl;
        file.close();
        cout << "Student added successfully!\n";
    }

    void displayStudents() {
        ifstream file("Students.txt");
        if (!file) {
            cout << "No records found.\n";
            return;
        }
        cout << "\n--- Student Records ---\n";
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Marks" << endl;
        cout << "-------------------------------------------\n";

        string line;
        while (getline(file, line)) {
            int pos1 = line.find(",");
            int pos2 = line.find(",", pos1 + 1);
            string sid = line.substr(0, pos1);
            string sname = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string smarks = line.substr(pos2 + 1);

            cout << left << setw(10) << sid << setw(20) << sname << setw(10) << smarks << endl;
        }
        file.close();
    }

    void updateStudent() {
        int uid;
        cout << "Enter ID to update: ";
        cin >> uid;

        ifstream file("Students.txt");
        ofstream temp("Temp.txt");
        bool found = false;
        string line;

        while (getline(file, line)) {
            int pos1 = line.find(",");
            int pos2 = line.find(",", pos1 + 1);
            int sid = stoi(line.substr(0, pos1));
            string sname = line.substr(pos1 + 1, pos2 - pos1 - 1);
            float smarks = stof(line.substr(pos2 + 1));

            if (sid == uid) {
                cout << "Enter new Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new Marks: ";
                cin >> marks;
                temp << sid << "," << name << "," << marks << endl;
                found = true;
            } else {
                temp << sid << "," << sname << "," << smarks << endl;
            }
        }
        file.close();
        temp.close();
        remove("Students.txt");
        rename("Temp.txt", "Students.txt");

        if (found) cout << "Record updated successfully!\n";
        else cout << "Record not found.\n";
    }

    void deleteStudent() {
        int did;
        cout << "Enter ID to delete: ";
        cin >> did;

        ifstream file("Students.txt");
        ofstream temp("Temp.txt");
        bool found = false;
        string line;

        while (getline(file, line)) {
            int pos1 = line.find(",");
            int pos2 = line.find(",", pos1 + 1);
            int sid = stoi(line.substr(0, pos1));
            string sname = line.substr(pos1 + 1, pos2 - pos1 - 1);
            float smarks = stof(line.substr(pos2 + 1));

            if (sid == did) {
                found = true;
                continue; // skip writing this record
            } else {
                temp << sid << "," << sname << "," << smarks << endl;
            }
        }
        file.close();
        temp.close();
        remove("Students.txt");
        rename("Temp.txt", "Students.txt");

        if (found) cout << "Record deleted successfully!\n";
        else cout << "Record not found.\n";
    }
};

int main() {
    Student s;
    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: s.addStudent(); break;
            case 2: s.displayStudents(); break;
            case 3: s.updateStudent(); break;
            case 4: s.deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}