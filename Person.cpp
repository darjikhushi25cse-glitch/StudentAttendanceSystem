#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {
    id = 0;
    name = "";
}

Person::Person(int i, const string& n) {
    id = i;
    name = n;
}

Person::~Person() {}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}