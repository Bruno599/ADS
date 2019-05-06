
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"
#include <fstream>

using namespace std;
int main()
{
	int result = Catch::Session().run();

	Tree newTree{};

	newTree.addNode("hans", 50, 2300, 41844);
	newTree.addNode("guenter", 55, 2500, 41836);

	newTree.printAll();

	system("PAUSE");
	return 0;
}