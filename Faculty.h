#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <string>

class Faculty : public Person {
private:
    std::string department;

public:
    // Constructors
    Faculty();
    Faculty(int id, const std::string& name, const std::string& department);

    // Getter
    std::string getDepartment() const;

    // Overridden display method for Runtime Polymorphism
    void display() const override;
};

#endif