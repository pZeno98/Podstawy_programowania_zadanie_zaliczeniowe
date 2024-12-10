#pragma once
#include "Biblioteki.h"

struct Node {
	int numer_studenta;
	string nazwisko;
	string imi�;
	double stypendium;
	string adress;
	Node* next;
	Node* prev;
	Node* head;
};

void add(Node &actual, int numer_studenta, string nazwisko, string imi�, double stypendium, string adress) {
	if (actual.head == nullptr) {
		actual.head = new Node{numer_studenta, nazwisko, imi�, stypendium, adress, nullptr, nullptr};
	}
	else {
		Node* iter = actual.head;
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = new Node{numer_studenta, nazwisko, imi�, stypendium, adress, nullptr, iter};
	}
}

void printStudents(Node& actual) {
	Node* iter = actual.head;
	while (iter != nullptr) {
		cout << iter->numer_studenta << " " << iter->nazwisko << " " << iter->imi� << " " << iter->stypendium << " " << iter->adress << endl;
		iter = iter->next;
	}
}

void printStudentsBackwards(Node& actual) {
	Node* iter = actual.head;
	while (iter->next != nullptr) {
		iter = iter->next;
	}
	while (iter != nullptr) {
		cout << iter->numer_studenta << " " << iter->nazwisko << " " << iter->imi� << " " << iter->stypendium << " " << iter->adress << endl;
		iter = iter->prev;
	}

}