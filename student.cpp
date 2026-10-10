#include "Student.h"
#include <iostream>

// Default Constructor
Student::Student() : Person(), className("") {}

// Parameterized Constructor using member initializer list
Student::Student(int id, const std::string& name, const std::string& className)
    : Person(id, name), className(className) {}

std::string Student::getClassName() const {
    return className;
}

void Student::display() const {
    std::cout << "[Student] ID: " << id 
              << " | Name: " << name 
              << " | Class: " << className << std::endl;
}
