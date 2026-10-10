#include "AttendanceSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

// Constructor with initial capacity allocation
AttendanceSystem::AttendanceSystem() {
    personCapacity = 5;
    personCount = 0;
    persons = new Person*[personCapacity];

    recordCapacity = 5;
    recordCount = 0;
    records = new AttendanceRecord[recordCapacity];
}

// Destructor releasing dynamically allocated memory
AttendanceSystem::~AttendanceSystem() {
    for (int i = 0; i < personCount; ++i) {
        delete persons[i];
    }
    delete[] persons;
    delete[] records;
}

// Dynamic resizing for Person pointer array
void AttendanceSystem::resizePersons() {
    personCapacity *= 2;
    Person** temp = new Person*[personCapacity];
    for (int i = 0; i < personCount; ++i) {
        temp[i] = persons[i];
    }
    delete[] persons;
    persons = temp;
}

// Dynamic resizing for AttendanceRecord array
void AttendanceSystem::resizeRecords() {
    recordCapacity *= 2;
    AttendanceRecord* temp = new AttendanceRecord[recordCapacity];
    for (int i = 0; i < recordCount; ++i) {
        temp[i] = records[i];
    }
    delete[] records;
    records = temp;
}

void AttendanceSystem::addStudent() {
    if (personCount >= personCapacity) {
        resizePersons();
    }
    int id;
    std::string name, className;
    std::cout << "Enter Student ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Student Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Class Name: ";
    std::getline(std::cin, className);

    persons[personCount++] = new Student(id, name, className);
    std::cout << "Student added successfully!\n";
}

void AttendanceSystem::addFaculty() {
    if (personCount >= personCapacity) {
        resizePersons();
    }
    int id;
    std::string name, department;
    std::cout << "Enter Faculty ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Faculty Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Department: ";
    std::getline(std::cin, department);

    persons[personCount++] = new Faculty(id, name, department);
    std::cout << "Faculty added successfully!\n";
}

void AttendanceSystem::markAttendance() {
    if (recordCount >= recordCapacity) {
        resizeRecords();
    }
    int recId, stdId, subId;
    std::string date, status;

    std::cout << "Enter Record ID: ";
    std::cin >> recId;
    std::cout << "Enter Student ID: ";
    std::cin >> stdId;
    std::cout << "Enter Subject ID: ";
    std::cin >> subId;
    std::cin.ignore();
    std::cout << "Enter Date (DD/MM/YYYY): ";
    std::getline(std::cin, date);
    std::cout << "Enter Status (Present/Absent): ";
    std::getline(std::cin, status);

    records[recordCount++] = AttendanceRecord(recId, stdId, subId, date, status);
    std::cout << "Attendance marked successfully!\n";
}

void AttendanceSystem::displayAllPersons() const {
    if (personCount == 0) {
        std::cout << "No persons registered in system.\n";
        return;
    }
    std::cout << "\n--- Registered Persons ---\n";
    for (int i = 0; i < personCount; ++i) {
        persons[i]->display(); // Runtime Polymorphism
    }
}

void AttendanceSystem::displayAllRecords() const {
    if (recordCount == 0) {
        std::cout << "No attendance records available.\n";
        return;
    }
    std::cout << "\n--- Attendance Records ---\n";
    for (int i = 0; i < recordCount; ++i) {
        records[i].display();
    }
}

void AttendanceSystem::searchRecordById() const {
    int searchId;
    std::cout << "Enter Record ID to Search: ";
    std::cin >> searchId;

    bool found = false;
    for (int i = 0; i < recordCount; ++i) {
        if (records[i].getRecordId() == searchId) {
            std::cout << "Record Found:\n";
            records[i].display();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Record ID " << searchId << " not found.\n";
    }
}

void AttendanceSystem::saveRecordsToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Unable to open file for writing: " + filename);
    }
    for (int i = 0; i < recordCount; ++i) {
        outFile << records[i].getRecordId() << ","
                << records[i].getStudentId() << ","
                << records[i].getSubjectId() << ","
                << records[i].getDate() << ","
                << records[i].getStatus() << "\n";
    }
    outFile.close();
    std::cout << "Records successfully saved to " << filename << "\n";
}

void AttendanceSystem::loadRecordsFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "No existing record file found (" << filename << "). Starting fresh.\n";
        return;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string token;

        int recId, stdId, subId;
        std::string date, status;

        std::getline(ss, token, ','); recId = std::stoi(token);
        std::getline(ss, token, ','); stdId = std::stoi(token);
        std::getline(ss, token, ','); subId = std::stoi(token);
        std::getline(ss, date, ',');
        std::getline(ss, status, ',');

        if (recordCount >= recordCapacity) {
            resizeRecords();
        }
        records[recordCount++] = AttendanceRecord(recId, stdId, subId, date, status);
    }
    inFile.close();
    std::cout << "Records successfully loaded from " << filename << "\n";
}
