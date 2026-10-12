#include "AttendanceRecord.h"
#include <iostream>

using namespace std;

AttendanceRecord::AttendanceRecord() {
    recordId = 0;
    studentId = 0;
    subjectId = "";
    date = "";
    status = "";
}

AttendanceRecord::AttendanceRecord(int rId, int sId, const string& subId, const string& d, const string& st) {
    recordId = rId;
    studentId = sId;
    subjectId = subId;
    date = d;
    status = st;
}

int AttendanceRecord::getRecordId() const { return recordId; }
int AttendanceRecord::getStudentId() const { return studentId; }
string AttendanceRecord::getSubjectId() const { return subjectId; }
string AttendanceRecord::getDate() const { return date; }
string AttendanceRecord::getStatus() const { return status; }

void AttendanceRecord::display() const {
    cout << "Record ID: " << recordId 
         << " | Student ID: " << studentId 
         << " | Subject: " << subjectId 
         << " | Date: " << date 
         << " | Status: " << status << "\n";
}

