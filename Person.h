#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    int id;
    std::string name;

public:
    Person();
    Person(int i, const std::string& n);
    virtual ~Person();

    int getId() const;
    std::string getName() const;

    virtual void display() const = 0;
};

#endif