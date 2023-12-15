#include <iostream>
#include <fstream>

int main() {

#ifdef DEBUG
	std::ostream& out = std::cout;
#else
	std::ofstream file;
	file.open("Out/Lab1/task1.out");
	std::ostream& out = file;
#endif

	std::pair<int, float> vector[10];
	int first = vector->first;
	float second = vector->second;

	float sum = 0.0f;

	for(int i = 0; i < 10; ++i) {
		vector[i].first = i;
		vector[i].second = i * 2.5f;
		//sum += vector[i].second;
	}

	for (const auto& item : vector) {
		std::cout << item.first << ' ' << std::endl;
	}

	for (const auto& item : vector) {
		sum += item.second;
	}

	std::cout << sum;

	return 0;
}
