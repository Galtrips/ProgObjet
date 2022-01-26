#include "item.h"
#include <iostream>
#include <cstring>

using namespace std;

Item::Item(const char* n, bool v) {
	int lg = strlen(n);
	Nom = new char[lg + 1];
	strcpy_s(Nom, lg + 1, n);
}

Item::Item() {
	
}

Item::~Item() {
	if (Nom != NULL) {
		delete[]Nom;
	}
}

char* Item::getNom() {
	return Nom;
}

bool Item::getValider() {
	return Valid�;
}

void Item::setNom(const char* n) {
	if (Nom != NULL) {
		delete[] Nom;
	}
	int lg = strlen(n) + 1;
	Nom = new char[lg];
	strcpy_s(Nom, lg, n);
}

void Item::setValider(bool v) {
	Valid� = v;
}

Item::Item(const Item& i) {
	
	setNom(i.Nom);
	setValider(i.Valid�);
}

void Item::Affiche() {
	cout << getValider() << endl;
	cout << getNom() << endl;
}

