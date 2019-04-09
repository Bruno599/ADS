#pragma once

#include <string>


class stackoutofstring
{
private:

	Node *ptr;

public:

	stackoutofstring(std::string item)
	{
		Node *ptr = new Node();
		ptr->data = item;

		if 

	}


};

class Node
{
public:

	std::string data;
	int *next;
	int *prev;
	Node() {};

};