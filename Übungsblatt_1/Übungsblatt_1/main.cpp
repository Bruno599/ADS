#include <iostream>
#include "FixedCapacityStackOfStrings.h"
#include <string>

using namespace std;

int main()
{

	FixedCapacityStackOfStrings test(5);

	if (test.isEmpty())
	{
		cout << "Der Stapel ist leer!" << endl;
	}

	string string1 = "ABCD";
	string string2 = "EFGH";
	string string3 = "IJKL";
	string string4 = "MNOP";
	string string5 = "QRST";
	string string6 = "UVWX";

	test.push(string1);
	test.push(string2);
	test.push(string3);
	test.push(string4);
	test.push(string5);
	//test.push(string6);

	if (test.isEmpty())
	{
		cout << "Der Stapel ist leer!" << endl;
	}
	else
	{
		cout << "Stapel ist gefuellt" << endl;
	}

	if (test.isFULL())
	{
		cout << "Der Stapel ist Voll" << endl;
	}

	test.print();
	
	system("Pause");

	return 0;

}