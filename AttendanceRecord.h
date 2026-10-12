#ifndef ATTENDANCERECORD_H
#define ATTENDANCERECORD_H

#include <string>

class AttendanceRecord {
private:
    int recordId;
    int studentId;
    std::string subjectId;
    std::string date;
    std::string status;

public:
    AttendanceRecord();
    AttendanceRecord(int rId, int sId, const std::string& subId, const std::string& d, const std::string& st);

    int getRecordId() const;
    int getStudentId() const;
    std::string getSubjectId() const;
    std::string getDate() const;
    std::string getStatus() const;

    void display() const;
};

#endif