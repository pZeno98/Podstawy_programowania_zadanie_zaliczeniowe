#pragma once
#include "Biblioteki.h"
class DataGenerator
{
public:
	//Zaczytywanie funkcji
public:
	void generate(int, vector <int>&);
	void display(string, vector <int>&);
	void display(string, double);
	void sortMethod(vector<int>&);
	void saveToFileBin(vector<int>&, string);
	void saveToFileTxt(vector<int>&, string);
	void readFromFileTxt(const string& fileTxt);
	void readAndDisplayBinary(const string&);
};

