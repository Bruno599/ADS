/*
* ADS Praktikum 2.2
* main.cpp
*
*/

#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:



//
///////////////////////////////////////
int main() {

	int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:

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
	test.searchNode("test5");


	//
	///////////////////////////////////////
	system("PAUSE");

	return 0;
}