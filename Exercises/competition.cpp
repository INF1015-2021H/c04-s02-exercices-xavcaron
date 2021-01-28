///
/// Traite les arguments de ligne de commande à l'aide de TCLAP.
///


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <vector>
#include <span>

#include <cppitertools/range.hpp>

#include "competition.hpp"

using namespace std;
using iter::range;


void readValues_v1(int values[], int numValues) { // values est un parametre out
	cout << "Enter grades" << "\n";  
	for (int i = 0; i < numValues; i++) {
		cin >> values[i];
	}
}

int getTotalGrade_v1(const int values[], int numValues) {
	int minVal = values[0];
	int maxVal = values[0];  // initialiser a premi"ere valeur du tableau
	int total = 0;
	for (int i = 0; i < numValues; i++) {
		total += values[i];
	};
	MinMax minmax = findMinMax_v1(values, numValues);

	return total - minmax.min - minmax.max;
}

MinMax findMinMax_v1(const int values[], int numValues) {
	int minVal = values[0];
	int maxVal = values[0];  // initialiser a premi"ere valeur du tableau
	for (int i = 0; i < numValues; i++) {
		if (values[i] < minVal) {
			minVal = values[i];
		}
		if (values[i] > maxVal) {
			maxVal = values[i];
		}
	}
	return {minVal, maxVal};
}

/*TODO*/void readValues_v2(...) {
	
}

int getTotalGrade_v2(...) {
	return {};
}

MinMax findMinMax_v2(...) {
	return {};
}

void readValues_v3(...) {
	
}

int getTotalGrade_v3(...) {
	return {};
}

MinMax findMinMax_v3(...) {
	return {};
}

void runCompetitionExample() {
	const int arraySize = 8;
	// Utilisation des *_v1
	{
		int values[arraySize];
		readValues_v1(values, arraySize);
		for (int v : values)
			cout << v << " ";
		cout << "\n";
		MinMax minmaxValues = findMinMax_v1(values, arraySize);
		int totalGrade = getTotalGrade_v1(values, arraySize);
		cout << "Total: " << totalGrade << "\n"
		     << "Min: " << minmaxValues.min << "\n"
		     << "Max: " << minmaxValues.max << "\n";
	}
	return;
	// Utilisation des *_v2
	{
		vector<int> values = {}; // TODO
		for (int v : values)
			cout << v << " ";
		cout << "\n";
		MinMax minmaxValues = findMinMax_v2(values);
		int totalGrade = getTotalGrade_v2(values);
		cout << "Total: " << totalGrade << "\n"
		     << "Min: " << minmaxValues.min << "\n"
		     << "Max: " << minmaxValues.max << "\n";
	}
	// Utilisation des *_v3
	{
		vector<int> values(arraySize);
		readValues_v3(values);
		for (int v : values)
			cout << v << " ";
		cout << "\n";
		MinMax minmaxValues = findMinMax_v3(values);
		int totalGrade = getTotalGrade_v3(values);
		cout << "Total: " << totalGrade << "\n"
		     << "Min: " << minmaxValues.min << "\n"
		     << "Max: " << minmaxValues.max << "\n";
	}
}

