#include "Ring.h"

Ring::Ring() 
{

};
void Ring::addNode(std::string descript, std::string data)
{
	RingNode* tmp = new RingNode(0,descript,data);
	if (checkifempty(this->anker))
	{
		this->anker = tmp;
		//anker->setAge(0);
		//anker->setDescription(descript);
		//anker->setData(data);
		anker->setNext(tmp);
		this->AnzahlNodes = 1;
		
	}
	else
	{
		RingNode* tmp2 = this->anker;
		if (this->AnzahlNodes == 6)
		{
			tmp2 = tmp2->getNext();
			tmp->setNext(tmp2->getNext());
			anker->setNext(tmp);
			anker = tmp;
			delete tmp2;
			updateNodes(anker);
			
		}
		else
		{
			tmp->setNext(tmp2->getNext());
			tmp2->setNext(tmp);
			anker = tmp;
			this->AnzahlNodes++;
			updateNodes(anker);
					
		}



	}
};
bool Ring::search(std::string data)
{
	RingNode* tmp = this->anker;
	for (int i = 1; i <= this->AnzahlNodes; i++)
	{
		if (data == tmp->getData())
		{
			return true;
		}
		else
		{
			tmp = tmp->getNext();
		}
	}
	return false;
};
bool Ring::search(std::string data, RingNode* &position)
{
	RingNode* tmp = this->anker;
	for (int i = 1; i <= this->AnzahlNodes; i++)
	{
		if (data == tmp->getData())
		{
			position = tmp;
			return true;
		}
		else
		{
			tmp = tmp->getNext();
		}
	}
	return false;
};
void Ring::print()
{
	RingNode* tmp = anker;
	//int b = 1;
	for (int i = 1; i <= this->AnzahlNodes; i++)
	{
		std::cout << "OldAge: " << tmp->getAge() << ", Descr: " << tmp->getDescription() << ", Data: " << tmp->getData() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		for (int j = 1; j <= this->AnzahlNodes-1; j++)
		{
			tmp = tmp->getNext();
		}
		
	}
};
bool Ring::checkifempty(RingNode* anker)
{
	if (anker == NULL)
		return true;
	else
		return false;
}
bool Ring::updateNodes(RingNode* position)
{
	RingNode * tmp = position->getNext();
	for(int i = 1; i < this->AnzahlNodes; i++)
	{
		tmp->setAge(tmp->getAge() + 1);
		tmp = tmp->getNext();
	}
	return true;
}
void Ring::printauswahl()
{
	int wert = 0;

	std::cout << "v0.1, by Dominik Schmitt" << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "1) Backup einfuegen " << std::endl;
	std::cout << "2) Backup suchen " << std::endl;
	std::cout << "3) Alle Backups ausgeben " << std::endl;
	std::cout << "Zum Beenden bitte X drücken " << std::endl << std::endl;
	std::cout << "Bitte geben Sie hier ihre auswahl ein: ";
	std::cin >> wert;

	auswahl(wert);
}

bool Ring::auswahl(int b)
{
	switch(b)
	{
	case 1 : 
		addnewBackup();
		return true;
		break;
	case 2 :
		searchforBackup();
		return true;
		break;
	case 3 :
		printallBackup();
		return true;
		break;
	default:
		return false;
		break;
	}
}
void Ring::addnewBackup()
{
	std::string descript, data;
	std::cout << "+Neuen Datensatz einfuegen" << std::endl << "Beschreibung ? > ";
	std::cin.ignore(1, '\n');
	std::getline(std::cin, descript);
	std::cout << "Daten ? > ";
	//std::cin.ignore(1, '\n');
	std::getline(std::cin, data);

	addNode(descript, data);

	if (search(data))
	std::cout << " Datensatz wurde hinzugefuegt." << std::endl;
	else
	std::cout << " Datensatz wurde nicht hinzugefuegt." << std::endl;

	std::cout << std::endl;
	printauswahl();

}
void Ring::searchforBackup()
{
	std::string data;
	std::cout << "+Nach Datensatz suchen" << std::endl << "+Nach welchen Daten soll gesucht werden ? ";
	std::cin.ignore(1, '\n');
	std::getline(std::cin, data);
	RingNode *tmp;

	if (search(data, tmp)) 
	{
		std::cout << "+ Gefunden in Backup : ";
		printentry(tmp);
	}

	std::cout << std::endl;
	printauswahl();
}
void Ring::printallBackup()
{
	this->print();
	std::cout << std::endl;
	printauswahl();
}
void Ring::printentry(RingNode* tmp)
{
	std::cout << "OldAge: " << tmp->getAge() << ", Descr: " << tmp->getDescription() << ", Data: " << tmp->getData() << std::endl;
}