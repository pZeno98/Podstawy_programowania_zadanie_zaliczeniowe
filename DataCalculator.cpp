#include "DataCalculator.h"

double DataCalculator::calculateAverageValue(vector<int>& vec) {
	//deklaracja zmiennych lokalnych
	int sum = 0;
	double averageNumber = 0;

	//dodanie elementow vectora
	for (int i = vec.size() - 1; i >= 0; i--) {
		sum += vec[i];
	}

	//wyliczenie œredniej (suma/rozmiar vectora)
	averageNumber = static_cast<double>(sum) / vec.size();
	return averageNumber;
}

double DataCalculator::showSmallestValueInVector(vector<int>& vec) {
	//wypisanie najmniejszej wartoœci z vectora
	return vec[0];
}
