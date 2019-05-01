#pragma once
#include "RingNode.h"
#include <iostream>

class Ring
{
private:

	int AnzahlNodes;
	RingNode* anker;

public:

	Ring();
	void addNode(std::string descript, std::string data);
	bool search(std::string data);
	bool search(std::string data, RingNode* &position);
	void print();
	bool checkifempty(RingNode* anker);
	bool updateNodes(RingNode* position);
	void printauswahl();
	bool auswahl(int b);
	void addnewBackup();
	void searchforBackup();
	void printallBackup();
	void printentry(RingNode* tmp);
	friend RingNode * get_anker(Ring& r);
	friend int get_AnzahlNodes(Ring& r); 
};