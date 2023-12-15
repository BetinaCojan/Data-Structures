#include <iostream>
#ifndef __GRADEBOOK_H__
#define __GRADEBOOK_H__

class Gradebook {
private:
	double *grades;
	int capacity; // max number of grades
	int count;    // current number of grades

public:
	Gradebook(int capacity) {
		this->grades = (double *)malloc(capacity * sizeof(double));
		this->capacity = capacity;
		this->count = 0;
	}

	~Gradebook() {
		free(grades);
	}

	void addGrade(double grade) {
		if (this->count < this->capacity) {
			this->grades[this->count] = grade;
			this->count ++;
		} else {
			std::cerr << "Maximum capacity has been reached" << std::endl;
		}
	}

	double average() {
		double sum = 0;
		for(int i = 0; i < count; i++) {
			sum += this->grades[i];
		}
		return sum / count;
	}
};

#endif // __GRADEBOOK_H__
