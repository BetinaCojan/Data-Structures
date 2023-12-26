#ifndef __MAPPING_ENTRY_H
#define __MAPPING_ENTRY_H

#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX_LENGTH 255

class MappingEntry {
private:
	int key;
	char *value;

public:
	// Constructor 
	MappingEntry(int key, char *value) {
		this->key = key;
		this->value = new char[strlen(value) + 1];
		strcpy(this->value, value);
	}

	// Destructor 
	~MappingEntry() {
		delete[] value;
	}

	// Getters for key and value 
	int getKey() const {
		return this->key;
	}

	const char* getValue() const {
		return this->value;
	}
};

#endif