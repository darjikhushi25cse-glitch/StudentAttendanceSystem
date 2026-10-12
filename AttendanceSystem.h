#ifndef ATTENDANCESYSTEM_H
#define ATTENDANCESYSTEM_H

#include "Person.h"
#include "AttendanceRecord.h"
#include <string>

class AttendanceSystem {
private:
    Person* persons[100];
    AttendanceRecord* records[100];
    int personCount;
    int recordCount;

public:
    AttendanceSystem();
    ~AttendanceSystem();

    void addStudent();
    void addFaculty();
    void displayAllPersons();
    void markAttendance();
    void displayAllRecords();
    void searchRecordById();
    void saveRecordsToFile(const std::string& filename = "attendance.txt");
    void loadRecordsFromFile(const std::string& filename = "attendance.txt");
};

#endif