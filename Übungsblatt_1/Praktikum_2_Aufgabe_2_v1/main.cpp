/*************************************************
* ADS Praktikum 2.2
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"
#include <fstream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:
void newInput(Tree& tree)
{
	std::cin.ignore();
	std::string name;
	int age = 0;
	double income = 0.0;
	int plz = 0;
	std::cout << "+ Bitte geben Sie den Datensatz ein\nName ?> ";
	std::getline(std::cin, name);
	std::cout << "Alter ?> ";
	std::cin >> age;
	std::cout << "Einkommen ?> ";
	std::cin >> income;
	std::cout << "PLZ ?> ";
	std::cin >> plz;
	tree.addNode(name, age, income, plz);
	std::cout << "+ Ihr Datensatz wurde eingefuegt\n\n";
}

void readCSV(Tree& tree)
{

	char input = 0;
	std::string data[4];
	std::cout << "+ Moechten Sie die Daten aus der Datei \"ExportZielanalyse.csv\"importieren (j/n) ?> ";
	std::cin >> input;
	if (input == 'j') {
		int counter = 0;
		std::ifstream csvread;
		csvread.open("ExportZielanalyse.csv", std::ios::in);
		if (csvread) {
			//Datei bis Ende einlesen und bei ; an neue Pos im Array schreiben...
			while (!csvread.eof()) {
				for (int i = 0; i < 3; ++i) {
					std::getline(csvread, data[i], ';');
				}
				std::getline(csvread, data[3], '\n');
				tree.addNode(data[0], std::stoi(data[1]), std::stod(data[2]), std::stoi(data[3]));
			}
		}

	}
	std::cout << "\n";
}

void deleteData(Tree& tree)
{
	std::cin.ignore();
	int nodePosID = 0;
	std::cout << "Bitte geben Sie den zu loeschenden Datensatz an\nPosID ?> ";
	std::cin >> nodePosID;
	tree.deleteNode(nodePosID);
	std::cout << "\n";
}

void searchName(Tree& tree)
{
	std::cin.ignore();
	std::string name;
	std::cout << "Bitte geben Sie den zu suchenden Datensatz an\nName ?> ";
	std::getline(std::cin, name);
	tree.searchNode(name);
}

//
///////////////////////////////////////
int main() {

	int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:
	char input = 0;
	Tree myTree{};
	std::cout << "===================================\nPerson Analyzer v19.84, by George Orwell\n";
	while (true) {
		std::cout << "1) Datensatz einfuegen, manuell\n2) Datensatz einfuegen, CSV Datei\n3) Datensatz loeschen\n4) Suchen\n5) Datenstruktur anzeigen\n6) quit\n?> ";
		std::cin >> input;

		if (input == '1') {
			newInput(myTree);
		}
		else if (input == '2') {
			readCSV(myTree);
		}
		else if (input == '3') {
			deleteData(myTree);
		}
		else if (input == '4') {
			searchName(myTree);
		}
		else if (input == '5') {
			myTree.printAll();
		}
		else if (input == '6') {
			break;
		}
		else {
			std::cout << "Keine gueltige Eingabe.\n\n";
		}
	}
	//
	///////////////////////////////////////
	system("PAUSE");

	return 0;
}