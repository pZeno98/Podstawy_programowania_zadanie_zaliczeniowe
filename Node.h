#pragma once
#include "Biblioteki.h"

struct Node {
	int numer_studenta;
	string nazwisko;
	string imiê;
	double stypendium;
	string adress;
	Node* next;
	Node* prev;
	Node* head;
};

void add(Node &actual, int numer_studenta, string nazwisko, string imiê, double stypendium, string adress) {
	if (actual.head == nullptr) {
		actual.head = new Node{numer_studenta, nazwisko, imiê, stypendium, adress, nullptr, nullptr};
	}
	else {
		Node* iter = actual.head;
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = new Node{numer_studenta, nazwisko, imiê, stypendium, adress, nullptr, iter};
	}
}

void printStudents(Node& actual) {
	Node* iter = actual.head;
	while (iter != nullptr) {
		cout << iter->numer_studenta << " " << iter->nazwisko << " " << iter->imiê << " " << iter->stypendium << " " << iter->adress << endl;
		iter = iter->next;
	}
}

void printStudentsBackwards(Node& actual) {
	Node* iter = actual.head;
	while (iter->next != nullptr) {
		iter = iter->next;
	}
	while (iter != nullptr) {
		cout << iter->numer_studenta << " " << iter->nazwisko << " " << iter->imiê << " " << iter->stypendium << " " << iter->adress << endl;
		iter = iter->prev;
	}

}