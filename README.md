# Student Attendance Management System

**Student Name:** Khushi H Darji  
**Enrollment No.:** IU2541230083  
**Course Code:** CPP55 (OOCP Project)  

---

## 1. Introduction

The Student Attendance Management System is a C++ console-based application created to automate institutional record-keeping. It allows users to register students and faculty members, log daily attendance, and search records cleanly. The project serves as a practical implementation of Object-Oriented Concepts and Programming (OOCP) with C++ File Handling.

---

## 2. Objectives

- Implement core C++ Object-Oriented principles in a real-world scenario.
- Build a structured entity model to differentiate between Students and Faculty.
- Ensure data persistence across application restarts using C++ file streams.
- Provide input validation and CLI buffer handling to prevent runtime execution errors.

---

## 3. Features

- Entity Registration: Add Students (with Course details) and Faculty (with Department details).
- Attendance Logging: Mark daily attendance with validation against existing Student IDs.
- Search & Filter: View attendance history filtered by specific Student ID.
- Automated Data Persistence: Read from and save data to attendance.txt on startup and shutdown.
- Buffer-Safe CLI: Robust input flushing (cin.ignore()) for multi-word input handling.

---

## 4. OOCP Concepts Implemented

- Encapsulation: Class attributes are private/protected and accessed via public getters and setters.
- Inheritance: Student and Faculty classes inherit base attributes (id, name) from the Person class.
- Polymorphism: Pure virtual function display() in Person overridden by derived classes.
- Dynamic Memory Management: Native pointer arrays allocated on the heap using new and cleaned via custom destructors (delete).
- File Stream Handling: Standard <fstream> file read/write operations for persistent storage.

---

## 5. System Requirements

- Operating System: Windows, Linux, or macOS
- Compiler: GCC / G++ supporting C++11 standard or higher
- IDE / Editor: Visual Studio Code, Code::Blocks, or Dev-C++

---

## 6. Project Structure

main.cpp
Person.h / Person.cpp
Student.h / Student.cpp
Faculty.h / Faculty.cpp
AttendanceRecord.h / AttendanceRecord.cpp
AttendanceSystem.h / AttendanceSystem.cpp
attendance.txt
README.md

---

## 7. Compilation and Execution

Compilation Command:
g++ main.cpp Person.cpp Student.cpp Faculty.cpp AttendanceRecord.cpp AttendanceSystem.cpp -o attendance.exe

Running the Application (Windows):
.\attendance.exe

Running the Application (Linux / macOS):
./attendance.exe

---

## 8. Data Storage

System data is persistently stored in attendance.txt. On launching attendance.exe, the application parses existing logs into memory. On exiting through the main menu option, memory arrays are serialized back to attendance.txt.

---

## 9. Testing and Conclusion

Testing Summary:
The application was subjected to 15 comprehensive test cases (T01–T15) covering CRUD operations, invalid ID input checks, boundary capacities, missing file handling, and restart persistence. The system achieved a 100% Pass Rate.

Conclusion:
The project successfully demonstrates how OOP paradigms (Inheritance, Polymorphism, Encapsulation) combine with persistent dynamic storage to create a clean, maintainable, and reliable C++ software application.
