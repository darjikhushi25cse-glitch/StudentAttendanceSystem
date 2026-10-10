#include "Faculty.h"
#include <iostream>

// Default Constructor
Faculty::Faculty() : Person(), department("") {}

// Parameterized Constructor using member initializer list
Faculty::Faculty(int id, const std::string& name, const std::string& department)
    : Person(id, name), department(department) {}

std::string Faculty::getDepartment() const {
    return department;
}

void Faculty::display() const {
    std::cout << "[Faculty] ID: " << id 
              << " | Name: " << name 
              << " | Department: " << department << std::endl;
}