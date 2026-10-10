#include "AttendanceSystem.h"
#include <iostream>
#include <exception>

void displayMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "      STUDENT ATTENDANCE SYSTEM          \n";
    std::cout << "=========================================\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Add Faculty\n";
    std::cout << "3. Display All Persons\n";
    std::cout << "4. Mark Attendance\n";
    std::cout << "5. Display All Attendance Records\n";
    std::cout << "6. Search Attendance Record\n";
    std::cout << "7. Save Records to File\n";
    std::cout << "8. Exit\n";
    std::cout << "=========================================\n";
    std::cout << "Enter your choice (1-8): ";
}

int main() {
    AttendanceSystem system;
    const std::string filename = "attendance.txt";

    // Load existing records from file on startup
    system.loadRecordsFromFile(filename);

    int choice = 0;
    while (choice != 8) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Please enter a number between 1 and 8.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    system.addStudent();
                    break;
                case 2:
                    system.addFaculty();
                    break;
                case 3:
                    system.displayAllPersons();
                    break;
                case 4:
                    system.markAttendance();
                    break;
                case 5:
                    system.displayAllRecords();
                    break;
                case 6:
                    system.searchRecordById();
                    break;
                case 7:
                    system.saveRecordsToFile(filename);
                    break;
                case 8:
                    std::cout << "Saving records before exiting...\n";
                    system.saveRecordsToFile(filename);
                    std::cout << "Thank you for using the Student Attendance System!\n";
                    break;
                default:
                    std::cout << "Invalid choice! Please select an option between 1 and 8.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    return 0;
}


