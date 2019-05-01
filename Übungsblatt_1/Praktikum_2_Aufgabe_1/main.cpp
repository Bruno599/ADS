#define CATCH_CONFIG_RUNNER
#include "Ring.h"
#include<iostream>
#include "catch.hpp"
#include <string>

using namespace std;

int main()
{
	int result = Catch::Session().run();
	Ring test;
	test.addNode("hallo3", "welt3");
	test.addNode("hallo", "welt");
	test.addNode("hallo1", "welt1");
	test.addNode("hallo2", "welt2");

	test.search("welt14");
	test.print();

	test.printauswahl();

	system("PAUSE");

	return 0;
}