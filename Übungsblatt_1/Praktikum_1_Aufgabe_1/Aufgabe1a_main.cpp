#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Aufgabe1a_List.h"
using namespace std;

int main(void)
{
	int result = Catch::Session().run();
	int i;
	List MyList;

	for (i = 0; i < 10; i++) {
		MyList.insertFront(i + 1);
		MyList.insertBack(i + 100);
	}

	cout << MyList;

	cout << "100: " << (MyList.search(100) ? "gefunden" : "nicht gefunden") << endl;
	cout << "99: " << (MyList.search(99) ? "gefunden" : "nicht gefunden") << endl << endl;

	while (MyList.getBack(i))
		cout << i << " ";
	cout << endl << endl;

	List MyList1, MyList2, MyList3;
	List * MyList_dyn = new List;

	for (i = 0; i < 10; i++) {
		MyList1.insertFront(i + 1);
		MyList2.insertBack(i + 100);
	}

	MyList1.format("MyList1\n<<", ", ", ">>\n\n");
	cout << MyList1;

	MyList_dyn->format("MyList_dyn\n<<", ", ", ">>\n\n");
	MyList_dyn->insertFront(-111);
	cout << MyList_dyn;

	MyList2.format("MyList2\n<<", ", ", ">>\n\n");
	cout << MyList2;

	MyList3 = MyList1 + MyList_dyn + MyList2;

	delete MyList_dyn;

	cout << "Groesse von MyList3: " << MyList3.size() << endl << endl;

	MyList3.format("MyList3\n<<", ", ", ">>\n\n");
	cout << MyList3 << endl;

	MyList3.swap(8, 103);

	cout << MyList3;

	if (MyList3.test())
		cout << "MyList3: Zeiger OK\n\n";
	else
		cout << "MyList3: Zeiger ******Error\n\n";
	
	//�berpr�fe swap

	List Mylist4;
	Mylist4.insertFront(5);
	Mylist4.insertFront(7);
	Mylist4.insertFront(9);
	Mylist4.insertFront(4);

	Mylist4.insertBack(3);
	Mylist4.insertBack(2);
	Mylist4.insertBack(4);
	Mylist4.insertBack(1);

	cout << Mylist4;

		Mylist4.swap(4, 5);

		cout << Mylist4;
	
		cout << endl << "// ueberfruefe ob pointer richtig gesetzt werden bei methode insert front und insert back" << endl <<endl;

	// �berfr�fe ob pointer richtig gesetzt werden bei methode insert front und insert back
	int number1 = 0;
	int number2 = 0;
	List * MyList5 = new List;
	MyList5->getFront(number1);
	MyList5->getBack(number2);

	cout << number1 << endl;
	cout << number2 << endl;

	MyList5->insertFront(5);
	MyList5->getBack(number1);

	cout << MyList5;
	cout << number1 << endl;

	
	MyList5->insertBack(8);
	MyList5->insertFront(9);
	MyList5->getFront(number2);

	cout << MyList5;
	cout << number2 << endl;

	//delete MyList5;

	List * MyList7 = new List;

	MyList7->insertBack(3);
	MyList7->insertBack(2);
	MyList7->insertBack(4);
	MyList7->insertBack(1);

	cout << MyList7 << endl;

	cout << endl << "// ueberpruefe was passiert wenn Liste mit 1 Knoten angef�gt wird." << endl << endl;

	// �berpr�fe was passiert wenn Liste mit 1 Knoten angef�gt wird.
	MyList7->insertBack(MyList5);

	cout << MyList7 << endl;

	cout << MyList5 << endl;

	cout << endl << "//Ueberpruefe was passiert wenn leere List eingef�gt wird" << endl << endl;
	//�berpr�fe was passiert wenn leere List eingef�gt wird
	MyList7->insertFront(MyList5);

	cout << MyList7 << endl;

	cout << endl <<"//ueberpruefe ob Loeschen von leerer Liste funktioniert" << endl << endl;

	//�berpr�fe ob L�schen von leerer Liste funktioniert

	delete MyList5;

	

	//List MyList6;
	//MyList6

	//cout << MyList5;



	system("PAUSE");
	return 0;
}
