#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H

#include <string>

class AttendanceRecord {
private:
    int recordId;
    int studentId;
    int subjectId;
    std::string date;   // Format: DD/MM/YYYY
    std::string status; // Present / Absent

public:
    // Constructors
    AttendanceRecord();
    AttendanceRecord(int recordId, int studentId, int subjectId, 
                     const std::string& date, const std::string& status);

    // Getters
    int getRecordId() const;
    int getStudentId() const;
    int getSubjectId() const;
    std::string getDate() const;
    std::string getStatus() const;

    // Display Record Details
    void display() const;
};

#endif