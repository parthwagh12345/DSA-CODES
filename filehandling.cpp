#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudentRecord(ofstream& file, const Student& student) {
    file << student.rollNumber << ' ' << student.name << ' ' << student.division << ' ' << student.address << endl;
}

void displayStudentRecord(ifstream& file, int targetRollNumber) {
    Student student;
    bool found = false;

    while (file >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == targetRollNumber) {
            found = true;
            cout << "Student Record Found:" << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student Record not found." << endl;
    }
}

void deleteStudentRecord(ifstream& inFile, int targetRollNumber) {
    Student student;
    ofstream tempFile("temp.txt");

    bool found = false;

    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == targetRollNumber) {
            found = true;
            cout << "Student Record Deleted:" << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
        } else {
            tempFile << student.rollNumber << ' ' << student.name << ' ' << student.division << ' ' << student.address << endl;
        }
    }

    if (!found) {
        cout << "Student Record not found." << endl;
    }

    inFile.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");
}

int main() {
    ofstream outFile("students.txt", ios::app);
    ifstream inFile("students.txt");

    if (!outFile || !inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int choice, rollNumber;
    Student newStudent;

    do {
        cout << "\n1. Add Student\n2. Display Student\n3. Delete Student\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> newStudent.rollNumber;
                cout << "Enter Name: ";
                cin >> newStudent.name;
                cout << "Enter Division: ";
                cin >> newStudent.division;
                cout << "Enter Address: ";
                cin.ignore(); // to clear the buffer
                getline(cin, newStudent.address);
                addStudentRecord(outFile, newStudent);
                cout << "Student record added successfully." << endl;
                break;

            case 2:
                cout << "Enter Roll Number to display: ";
                cin >> rollNumber;
                displayStudentRecord(inFile, rollNumber);
                break;

            case 3:
                cout << "Enter Roll Number to delete: ";
                cin >> rollNumber;
                deleteStudentRecord(inFile, rollNumber);
                inFile.open("students.txt");  // Reopen the file after deletion
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    outFile.close();
    inFile.close();

    return 0;
}


 