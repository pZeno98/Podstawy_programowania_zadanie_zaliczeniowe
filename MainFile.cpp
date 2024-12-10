#include "DataGenerator.h"
#include "DataCalculator.h"
#include "Node.h"

DataGenerator dg;
DataCalculator dc;
Node node;

string fileVector = "Vector_";
string fileName = "�yluk_Piotr";
string fileBin = ".bin";
string fileTxt = ".txt";
char choice = 0;

//Odniesienie do metody wywo�anej poni�ej
void zad_1(int amountOfGeneratedNumbers);
void zad_2(int amountOfGeneratedNumbers);
void zad_3();
void info();
//Plik wykonawczy Main
int main() {
	//Ustawienie j�zyka z polskimi znakami
	system("chcp 1250");

	cout << "Cze��! Wybierz, kt�re zadanie chcesz wy�wietli�:" << endl;
	info();

	//Menu
	do {
		std::cin >> choice;
		switch (choice)
		{
			//zad.1
		case '1':
			zad_1(200);
			info();
			break;
			//zad.2
		case '2':
			zad_2(50);
			info();
			break;
			//zad.3
		case '3':
			zad_3();
			info();
			break;
			//Zako�czenie dzia�ania petli
		case '4':
			cout << "Dzi�ki za sprawdzenie zadania!" << endl;
			return 0;
			//Podanie niepoprawnego numeru
		default:
			cout << "Poda�e� z�y numer. Wybierz jeszcze raz." << endl;
			break;
		}
	} while (choice != (1 | 2 | 3));
	return 0;
}

void zad_1(int amountOfGeneratedNumbers) {
	//Zainicjowanie tablicy oraz nazwy pliku
	vector <int> vector;

	//Generowanie losowych cyfr, oraz zapis w tablicy
	dg.generate(amountOfGeneratedNumbers, vector);

	//Wy�wietlenie zawarto�ci tablicy przed posortowanie jej element�w
	dg.display("Przed posortowaniem:", vector);

	//Sortowanie element�w w tablicy
	dg.sortMethod(vector);

	//Wy�wietlenie element�w tablicy od najmniejszego elementu do najwi�kszego
	dg.display("Posortowane od najmniejszej do najwi�kszej", vector);

	//Zapis plik�w do pliku .txt oraz .bin
	dg.saveToFileBin(vector, fileName + fileBin);
	dg.saveToFileTxt(vector, fileName + fileTxt);

	dg.readFromFileTxt(fileName + fileTxt);

	dg.readAndDisplayBinary(fileName + fileBin);

	//Otworzenie pliku.txt
	system(("notepad.exe " + fileName + fileTxt).c_str());
}

void zad_2(int amountOfGeneratedNumbers) {
	vector <int> vector;
	//generowanie losowych warto�ci
	dg.generate(amountOfGeneratedNumbers, vector);

	//sortowanie tablicy
	dg.sortMethod(vector);

	//wy�wietlenie posortowanego vectora
	dg.display("Posortowany vector", vector);

	//obliczenie sredniej wartosci w tablicy
	double avgNumber = dc.calculateAverageValue(vector);

	//wyswietlnie sredniej wartosci tablicy
	dg.display("Srednia wartosc vectora: ", avgNumber);

	//najmniejsza liczba w vectorze
	dg.display("Najmniejsza liczba vectora: ", dc.showSmallestValueInVector(vector));

	//zapis pliku txt
	dg.saveToFileTxt(vector, fileVector + fileName + fileTxt);

	//otworzenie pliku txt
	system(("notepad.exe " + fileVector + fileName + fileTxt).c_str());

}

void zad_3() {
	node;
	add(node, 01, "Budy�", "Miros�aw", 1200.00, "3 maja, Katowice");
	add(node, 02, "Miodek", "Czes�aw", 1450.00, "Krakowska 11, Katowice");
	add(node, 03, "�yluk", "Piotr", 1100.00, "W�adys�awa Orkana 18, Katowice");
	add(node, 04, "Boromir", "Przemys�aw", 1400.00, "Powsta�c�w 12, Katowice");
	add(node, 05, "Bry�", "Konrad", 700.00, "Miodowa 3, Katowice");
	cout << endl;
	cout << "Wypisanie listy od pocz�tku do ko�ca" << endl << endl;
	printStudents(node);
	cout << endl;
	cout << "Wypisanie listy od ko�ca do pocz�tku" << endl << endl;
	printStudentsBackwards(node);
}

void info() {
	cout << endl << endl;
	cout << "Aby zamkn�� program wybierz 4. Aby przej�� do kolejnego zadania wybierz jego numer" << endl;
	cout << endl;
	cout << "Zad. 1 - generowanie tablicy 200 el oraz zapis pliku txt oraz bin." << endl;
	cout << "Wybierz 1" << endl;
	cout << endl;
	cout << "Zad. 2 - generowanie vectora 50 elementow, sortowanie, oraz pokazanie jego sredniej i najmniejszego elementu" << endl;
	cout << "Wybierz 2" << endl;
	cout << endl;
	cout << "Zad. 3 - Lista dwukierunkowa" << endl;
	cout << "Wybierz 3" << endl << endl;
	cout << endl;
	cout << "======== Aby zamkn�� program wybierz 4! ========" << endl;
}