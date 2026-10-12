#include "AttendanceSystem.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

AttendanceSystem::AttendanceSystem() {
    personCount = 0;
    recordCount = 0;
}

AttendanceSystem::~AttendanceSystem() {
    for (int i = 0; i < personCount; i++) {
        delete persons[i];
    }
    for (int i = 0; i < recordCount; i++) {
        delete records[i];
    }
}

void AttendanceSystem::addStudent() {
    if (personCount >= 100) {
        cout << "Error: Storage full for persons!\n";
        return;
    }

    int id;
    string name, className;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Class/Course Name: ";
    getline(cin, className);

    persons[personCount++] = new Student(id, name, className);
    cout << "Student added successfully!\n";
}

void AttendanceSystem::addFaculty() {
    if (personCount >= 100) {
        cout << "Error: Storage full for persons!\n";
        return;
    }

    int id;
    string name, department;

    cout << "Enter Faculty ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Department: ";
    getline(cin, department);

    persons[personCount++] = new Faculty(id, name, department);
    cout << "Faculty added successfully!\n";
}

void AttendanceSystem::displayAllPersons() {
    if (personCount == 0) {
        cout << "No persons registered yet.\n";
        return;
    }
    cout << "\n--- REGISTERED PERSONS ---\n";
    for (int i = 0; i < personCount; i++) {
        persons[i]->display();
    }
}

void AttendanceSystem::markAttendance() {
    if (recordCount >= 100) {
        cout << "Error: Storage full for attendance records!\n";
        return;
    }

    int recordId, studentId;
    string subjectId, date, status;

    cout << "Enter Record ID: ";
    cin >> recordId;

    cout << "Enter Student ID: ";
    cin >> studentId;

    // Student Validation Check
    bool studentFound = false;
    for (int i = 0; i < personCount; i++) {
        if (persons[i]->getId() == studentId) {
            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        cout << "Error: Student ID " << studentId << " not found in system! Please add student first.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter Subject ID: ";
    cin >> subjectId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Date (DD/MM/YYYY): ";
    getline(cin, date);

    cout << "Enter Status (Present/Absent): ";
    getline(cin, status);

    records[recordCount++] = new AttendanceRecord(recordId, studentId, subjectId, date, status);
    cout << "Attendance marked successfully!\n";
}

void AttendanceSystem::displayAllRecords() {
    if (recordCount == 0) {
        cout << "No attendance records found.\n";
        return;
    }
    cout << "\n--- ATTENDANCE RECORDS ---\n";
    for (int i = 0; i < recordCount; i++) {
        records[i]->display();
    }
}

void AttendanceSystem::searchRecordById() {
    if (recordCount == 0) {
        cout << "No attendance records available to search.\n";
        return;
    }

    int searchId;
    cout << "Enter Student ID to Search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < recordCount; i++) {
        if (records[i]->getStudentId() == searchId) {
            records[i]->display();
            found = true;
        }
    }

    if (!found) {
        cout << "No records found for Student ID: " << searchId << "\n";
    }
}

void AttendanceSystem::saveRecordsToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for saving!\n";
        return;
    }

    file << recordCount << "\n";
    for (int i = 0; i < recordCount; i++) {
        file << records[i]->getRecordId() << " "
             << records[i]->getStudentId() << " "
             << records[i]->getSubjectId() << " "
             << records[i]->getDate() << " "
             << records[i]->getStatus() << "\n";
    }

    file.close();
    cout << "Records saved successfully to " << filename << "\n";
}

void AttendanceSystem::loadRecordsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) return;

    file.close();
}