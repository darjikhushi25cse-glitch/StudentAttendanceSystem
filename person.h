#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

// Abstract Base Class
class Person {
protected:
    int id;
    std::string name;

public:
    // Constructors
    Person() : id(0), name("") {}
    Person(int id, const std::string& name) : id(id), name(name) {}

    // Virtual Destructor for safe polymorphic deletion
    virtual ~Person() {}

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }

    // Pure Virtual Function (Enforces Runtime Polymorphism)
    virtual void display() const = 0;
};

#endif
