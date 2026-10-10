#ifndef ATTENDANCE_SYSTEM_H
#define ATTENDANCE_SYSTEM_H

#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "AttendanceRecord.h"
#include <string>

class AttendanceSystem {
private:
    // Dynamic array for Persons (Polymorphism via base class pointers)
    Person** persons;
    int personCount;
    int personCapacity;

    // Dynamic array for Attendance Records
    AttendanceRecord* records;
    int recordCount;
    int recordCapacity;

    // Helper functions for dynamic array expansion
    void resizePersons();
    void resizeRecords();

public:
    AttendanceSystem();
    ~AttendanceSystem();

    // Core System Operations
    void addStudent();
    void addFaculty();
    void markAttendance();
    void displayAllPersons() const;
    void displayAllRecords() const;
    void searchRecordById() const;

    // File I/O operations
    void saveRecordsToFile(const std::string& filename) const;
    void loadRecordsFromFile(const std::string& filename);
};

#endif
