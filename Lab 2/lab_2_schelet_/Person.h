#ifndef __PERSON_H
#define __PERSON_H

#include <stdio.h>
#include <string.h>

class Person {
public:
	char* name;
	int age;

	Person(char* newName, int newAge) {
		this->age = newAge;
		this->name = new char[strlen(newName) + 1];
		strcpy(this->name, newName);
	}

	Person(const Person& other) {
		this->age = other.age;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}

	Person operator=(const Person& other) {
		if (this != &other) {
			delete[] this->name;
			this->age = other.age;
			this->name = new char[strlen(other.name) + 1];
			strcpy(this->name, other.name);
		}
		return *this;
	}

	~Person() { 
		delete[] this->name;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Person& person);
};

	std::ostream& operator<<(std::ostream& out, const Person& person) {
		out << person.name << "'s age is " << person.age << '\n';
		return out;
	}

#endif