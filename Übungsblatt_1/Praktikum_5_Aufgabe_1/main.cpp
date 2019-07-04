#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{
	Catch::Session().run();

	/*
	Graph G;
	G.init("graph1.txt");

	G.printAll();

	system("pause");

	*/

	int auswahl;
	bool graphloaded = false;
	bool exit = true;
	string file;
	Graph G;

	
	while(exit)
	{
			cout << "\nWorking on Graphs. Please choose:" << endl;
			cout << "1) Graph einlesen" << endl;
			cout << "2) Tiefensuche" << endl;
			cout << "3) Breitensuche" << endl;
			cout << "4) Prim" << endl;
			cout << "5) Kruskal" << endl;
			cout << "6) Print Graph" << endl;
			cout << "0 zum beenden" << endl;
			cout << "?- ";
			cin >> auswahl;

			switch (auswahl)
			{
			case 1:

				do
				{
					graphloaded = false;
					cin.ignore(1000, '\n');
					cout << "Bitte geben Sie den Dateinamen ein: ";
					getline(cin, file);

					if (G.init(file))
					{
						cout << "\nDie Datei konnte erfolgreich geladen werden.\n\n";
						graphloaded = true;

						system("pause");
					}
					else
					{
						cout << "\nDer Dateiname existiert nicht, oder konnte nicht gefunden werden.\n\n";
						file.clear();

						system("pause");
					}

				} while (file.length() < 1);



				break;
		case 2:

			if (graphloaded)
			{
				int startknoten;
				do
				{

					cout << "Bitte geben Sie den Startknoten ein: ";
					cin >> startknoten;

					if (!G.checkIfNodeExist(startknoten))
					{
						cout << "\nKnotennicht im Graphen vorhanden";
					}

				} while (!G.checkIfNodeExist(startknoten));

				if (G.depthSearchRek(startknoten))
				{
					cout << "\nTiefensuche war erfolgreich, alle Nodes wurden gefunden\n\n";

					system("pause");
				}
				else
				{
					cout << "\n Tiefensuche war nicht erfolgreich, nicht alle Nodes wurden gefunden\n\n";

					system("pause");
				}

			}
			else
			{
				cout << "\n Kein Graph geladen.\n\n";
				system("pause");
			}


			break;
		case 3:

			if (graphloaded)
			{
				int startknoten;
				do
				{

					cout << "Bitte geben Sie den Startknoten ein: ";
					cin >> startknoten;

					if (!G.checkIfNodeExist(startknoten))
					{
						cout << "\nKnotennicht im Graphen vorhanden\n\n";
					}

				} while (!G.checkIfNodeExist(startknoten));

				if (G.breadthSearchIter(startknoten))
				{
					cout << "\n Tiefensuche war erfolgreich, alle Nodes wurden gefunden\n\n";

					system("pause");
				}
				else
				{
					cout << "\n Tiefensuche war nicht erfolgreich, nicht alle Nodes wurden gefunden\n\n";

					system("pause");
				}
			}
			else
			{
				cout << "\n Kein Graph geladen.\n\n";

				system("pause");
			}

			break;
		case 4:

			if (graphloaded)
			{
				int startknoten;
				do
				{

					cout << "Bitte geben Sie den Startknoten ein: ";
					cin >> startknoten;

					if (!G.checkIfNodeExist(startknoten))
					{
						cout << "\nKnotennicht im Graphen vorhanden\n\n";
					}

				} while (!G.checkIfNodeExist(startknoten));

				cout << "Der Grap hat ein totales Gewicht von " << G.prim(startknoten) << endl << endl;

				system("pause");
			}
			else
			{
				cout << "\n Kein Graph geladen.\n\n";

				system("pause");
			}


			break;
		case 5:

			if (graphloaded)
			{
				cout << "Der Grap hat ein totales Gewicht von " << G.kruskal() << endl << endl;

				system("pause");
			}
			else
			{
				cout << "\n Kein Graph geladen.\n\n";

				system("pause");
			}

			break;
		case 6:

			if (graphloaded)
			{
				cout << endl;

				G.printAll();

				cout << endl;

				system("pause");

			}
			else
			{
				cout << "\n Kein Graph geladen.\n\n";
			}


			break;
		case 0:

			exit = false;

			break;
		
		}
	}
	
	return 0;
}