/*
* ADS Praktikum 2.2
* main.cpp
*
*/

#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"
#include <fstream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden f�rs Men� hier:
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

void readCSV(Tree* tree)
{
	char yesNo;
	std::cout << "+ Moechten Sie die Datei \"Export Zielanalyse.csv\" importieren? (j/n) ?> " << std::endl;
	std::cin >> yesNo;

	if (yesNo == 'j') {

		
	std::ifstream file("./ExportZielanalyse.csv");

	std::string line;
	std::string str[4];

	//name;age;income;plz

	while (std::getline(file, line)) {
		int j = 0;
		int last = -1;
		for (int i = 0; i < line.size(); i++) {
			if (line.at(i) == ';') {
				str[j] = line.substr(last + 1, i - last - 1);

				j++;
				last = i;
			}
		}
		str[j] = line.substr(last + 1, line.size() - last - 1);

		tree->addNode(str[0], std::stoi(str[1]), std::stod(str[2]), std::stoi(str[3]));
	}

	std::cout << "+ Daten wurden dem Baum hinzugefuegt." << std::endl << std::endl;
	
	}
	else if (yesNo == 'n') {
		
	}
	else {
		std::cout << "+ Ungeueltige Eingabe, bitte versuchen Sie es erneut." << std::endl << std::endl;
		
	}
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
	/*
	Tree test;
	test.addNode("test1", 23, 2300, 41844);
	test.addNode("test4", 26, 2300, 41844);
	test.addNode("test2", 24, 2300, 41844);
	test.addNode("test3", 25, 2300, 41844);
	test.addNode("test4", 26, 2355, 41844);
	test.addNode("test5", 27, 2300, 41844);
	test.addNode("test4", 28, 2300, 41844);

	test.searchNode("test4");
	test.searchNode("test5");
	test.deleteNode(44171);
	test.searchNode("test4");
	test.searchNode("test5");
	*/

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
			readCSV(&myTree);
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

	//
	///////////////////////////////////////
	system("PAUSE");

	return 0;
}