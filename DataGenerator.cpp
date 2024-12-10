#include "DataGenerator.h"

void DataGenerator::generate(int ilo��, vector<int>& vec) {
	// srand u�yte w celu generowania liczb losowych w oparciu o czas (za ka�dym razem inne liczby)
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < ilo��; i++) {
		//D�ugo�� listy jest nieokre�lona w vectorze, wi�c za ka�dym razem pchamy wygenerowana liczbe na koniec stosu
		vec.push_back(rand() % 1000);
	}
}

void DataGenerator::display(string text, vector<int>& vec) {
	cout << endl << endl << text << endl;
	//Wy�wietlamy ka�dy element tablicy
	for (int i = 0; i < vec.size(); i++) {
		cout << "El na pozycji " << i + 1 << " to: " << vec[i] << endl;
	}
}

void DataGenerator::display(string text, double value) {
	//wypisanie tekstu
	cout << endl << endl << text << value << endl;
}

void DataGenerator::sortMethod(vector<int>& vec) {
	//sortowanie vectora od poczatku do konca
	std::sort(vec.begin(), vec.end());
}

void DataGenerator::saveToFileBin(vector<int>& vec, string fileBin) {
	//Tworzymy plik binarny
	std::ofstream file(fileBin, std::ios::binary);
	if (file.is_open()) {
		//zapisujemy do niego warto�ci z tablicy
		file.write(reinterpret_cast<const char*>(vec.data()), vec.size() * sizeof(int));
		file.close();
	}
	else {
		std::cerr << "Nie uda�o si� otworzy� pliku binarnego do zapisu." << std::endl;
	}
}

void DataGenerator::saveToFileTxt(vector<int>& vec, string fileTxt) {
	//Tworzymy plik .txt
	std::ofstream file(fileTxt);
	if (file.is_open()) {
		//Zapisujemy kolejno ka�dy element z tablicy w pliku .txt
		for (int i = 0; i < vec.size(); i++) {
			file << "El na pozycji " << i + 1 << " to: " << vec[i] << endl;
		}
		file.close();
	}
	else {
		std::cerr << "Nie uda�o si� otworzy� pliku txt do zapisu." << std::endl;
	}
}

void DataGenerator::readFromFileTxt(const string& fileTxt) {
	//Otworzenie pliku .txt
	std::ifstream file(fileTxt);
	if (file.is_open()) {
		//Wygenerowanie zmiennej lokalnej, do kt�rej b�dzie pobierana warto�� z danej linii
		string line;
		cout << endl << endl << "\Odczyt danych z pliku .txt '" << fileTxt << "':" << endl;

		//Pobieranie warto�ci linii i przypisywanie do zmiennej lokalnej
		while (getline(file, line)) {
			//drukowanie zmiennej lokalnej
			cout << line << endl;
		}

		file.close();
	}
	else {
		cout << "Nie mo�na otworzy� pliku .txt: " << fileTxt << endl;
	}

}

void DataGenerator::readAndDisplayBinary(const string& filename) {
	std::ifstream file(filename, std::ios::binary);
	if (file.is_open()) {
		//Pobranie informacji na temat rozmiaru pliku
		file.seekg(0, std::ios::end);
		std::streampos fileSize = file.tellg();
		file.seekg(0, std::ios::beg);

		// Utworzenie wektora, kt�ry b�dzie przechowywa� dane z pliku
		vector<int> numbers(fileSize / sizeof(int));

		// Odczytanie numer�w z pliku
		file.read(reinterpret_cast<char*>(numbers.data()), fileSize);

		// Wy�wietlenie danych z pliku
		cout << endl << endl << "Numery z pliku binarnego: '" << filename << "':" << endl;
		for (size_t i = 0; i < numbers.size(); i++) {
			cout << "Numer z pliku binarnego " << i + 1 << " to: " << numbers[i] << endl;
		}

		file.close();
	}
	else {
		cout << "Nie mo�na otworzy� pliku .bin: " << filename << endl;
	}
}
