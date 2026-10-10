#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

class Student : public Person {
private:
    std::string className;

public:
    // Constructors
    Student();
    Student(int id, const std::string& name, const std::string& className);

    // Getter
    std::string getClassName() const;

    // Overridden display method for Runtime Polymorphism
    void display() const override;
};

#endif
