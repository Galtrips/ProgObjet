#include "item.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

Item* liste[20];

void init_liste() {
	for (int i = 0; i < 20; i++) {
		liste[i] = nullptr;
	}
}

void addItem(const char* n, bool v) {
	
	bool Created = false;
	for (int i = 0; i < 20; i++) {
		if (liste[i] == nullptr && Created == false) {
			Created = true;
			liste[i] = new Item;
			liste[i]->setNom(n);
			liste[i]->setValider(v);
		}
	}
}

void delItem(int c) {

	for (int i = c - 1; i < 19; i++) {

		liste[i]->setNom(liste[i + 1]->getNom());
		liste[i]->setValider(liste[i + 1]->getValider());

	}

	int i = 19;

	delete liste[i];
	liste[i] = nullptr;

}

void nettoyer() {
	
	for (int i = 0; i < 20; i++) {
		
		if (liste[i] != NULL) {
			delete liste[i];
			liste[i] = nullptr;
		}

	}
}

void saveList() {
	ofstream sortie("save.txt", ios::trunc);
	if (!sortie) {
		cout << "probleme de creation de fichier" << endl;
	}
	else {
		for (int i = 0; i < 20; i++) {
			if (liste[i] != nullptr)
				sortie << i+1 << ";" << liste[i]->getNom() << ";" << liste[i]->getValider() << endl;
		}
	}
	sortie.close();
}

void loadList() {
	ifstream entrer("save.txt", ios::in);
	if (!entrer) {
		cout << "probleme de creation de fichier" << endl;
	}
	else {
		while (!entrer.eof()) {
			char Ligne[200];
			entrer.getline(Ligne, 200, ';');
			int indice = atoi(Ligne) - 1;
			entrer.getline(Ligne, 200, ';');
			liste[indice] = new Item;
			liste[indice]->setNom(Ligne);
			entrer.getline(Ligne, 200);
			liste[indice]->setValider(atoi(Ligne));
		}
	}
	entrer.close();
}

void afficherListe() {
	int i = 0; 
	cout << "--------------" << endl;
	while (liste[i] != nullptr && i < 20) {
		if (liste[i] != NULL) {
			cout << "Case " << i + 1 << endl;
			cout << liste[i]->getNom() << endl;
			cout << liste[i]->getValider() << endl;
			cout << "--------------" << endl;
			i++;
		}
	}
	
}

int main(int argc, char* argv[]){

	init_liste();

	/*addItem("Carottes", true);
	addItem("Brocoli", false);
	addItem("Patates", false);
	addItem("Tomate", true);
	addItem("Pommes", false);
	addItem("Poire", true);
	addItem("Bananes", false);
	addItem("Salade", false);
	addItem("Citron", true);
	addItem("PetitPoid", false);
	addItem("Pitaya", true);
	addItem("Ananas", false);
	addItem("Epinard", false);
	addItem("Mais", true);
	addItem("Ravioli", false);
	addItem("Steak", true);
	addItem("Frommage", false);
	addItem("Lait", false);
	addItem("Oeuf", true);
	addItem("Killua", false);

	afficherListe();

	delItem(4);*/


	loadList();
	afficherListe();
	
	
	nettoyer();

	return 0;
}