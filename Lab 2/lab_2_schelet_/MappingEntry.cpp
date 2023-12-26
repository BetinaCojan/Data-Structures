#include <fstream>
#include <iostream>

#include "MappingEntry.h"

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab2/task3.out");
	std::ostream& out = file;
#endif

	char value[] = "MappingEntryValue";
	MappingEntry* entry = new MappingEntry(1, value);
	out << "Entry's value: " << entry->getValue() << std::endl;

	delete entry;
 
#ifndef DEBUG
	file.close();
#endif

	return 0;
}