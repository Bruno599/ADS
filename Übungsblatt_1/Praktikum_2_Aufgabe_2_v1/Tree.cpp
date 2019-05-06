/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Tree::calculateNodePosID(int age, int plz, double income)
{
	return age + plz + income;
}

void Tree::searchNodeByName(TreeNode* tmp, std::string name, bool &found)
{
	if (tmp != nullptr)
	{
		if (tmp->getLeft() != nullptr)
		{
			searchNodeByName(tmp->getLeft(), name, found);
		}
		if (tmp->getName() == name)
		{
			if (!found)
			{
				std::cout << "+Fundstellen: " << std::endl;
			}
			tmp->print();
			found = true;
		}
		if (tmp->getRight() != nullptr)
		{
			searchNodeByName(tmp->getRight(), name, found);
		}
	}
}

TreeNode* Tree::searchNodePosID(TreeNode* tmp, int nodePosID, TreeNode *&prev)
{
	while (tmp != nullptr && tmp->getNodePosID() != nodePosID)
	{
		if (nodePosID < tmp->getNodePosID())
		{
			prev = tmp;
			tmp = tmp->getLeft();
		}
		else
		{
			prev = tmp;
			tmp = tmp->getRight();
		}
	}
	return tmp;
}

TreeNode* Tree::findMinNode(TreeNode* origin, TreeNode *&prev)
{
	TreeNode* minNode = origin;

	while (minNode->getLeft() != nullptr)
	{
		prev = minNode;
		minNode = minNode->getLeft();
	}

	return minNode;
}

void Tree::printAllRek(TreeNode* tmp)
{
	if (tmp != nullptr)
	{
		tmp->print();
		printAllRek(tmp->getLeft());
		printAllRek(tmp->getRight());
	}
}

Tree::Tree()
{
	anker = nullptr;
	nodeIDCounter = 0;
}

void Tree::addNode(std::string name, int age, double income, int plz)
{
	TreeNode* newEntry = new TreeNode(calculateNodePosID(age, plz, income), nodeIDCounter++, name, age, income, plz);

	if (anker == nullptr)
	{
		anker = newEntry;
	}
	else
	{
		TreeNode *tmp = anker;
		TreeNode* prev = anker;

		while (tmp != nullptr)
		{
			if (newEntry->getNodePosID() < tmp->getNodePosID())
			{
				prev = tmp;
				tmp = tmp->getLeft();
			}
			else
			{
				prev = tmp;
				tmp = tmp->getRight();
			}
		}

		if (newEntry->getNodePosID() < prev->getNodePosID())
		{
			prev->setLeft(newEntry);
		}
		else
		{
			prev->setRight(newEntry);
		}
	}
}

void Tree::deleteNode(int nodePosID)
{
	TreeNode* prev = anker;
	TreeNode* node = searchNodePosID(anker, nodePosID, prev);

	//Node hat keinen Nachfolger
	if (node->getLeft() == nullptr && node->getRight() == nullptr)
	{
		if (node == anker)
		{
			anker = nullptr;
		}
		else if (node->getNodePosID() < prev->getNodePosID())
		{
			prev->setLeft(nullptr);
		}
		else
		{
			prev->setRight(nullptr);
		}

		delete node;
	}
	//Node hat 1 Nachfolger
	else if (node->getLeft() == nullptr || node->getRight() == nullptr)
	{
		if (node->getLeft() == nullptr)
		{
			if (node == anker)
			{
				anker = node->getRight();
			}
			else if (node->getNodePosID() < prev->getNodePosID())
			{
				prev->setLeft(node->getRight());
			}
			else
			{
				prev->setRight(node->getRight());
			}
		}
		else if (node->getRight() == nullptr)
		{
			if (node == anker)
			{
				anker = node->getLeft();
			}
			else if (node->getNodePosID() < prev->getNodePosID())
			{
				prev->setLeft(node->getLeft());
			}
			else
			{
				prev->setRight(node->getLeft());
			}
		}

		if (node == anker)
		{

		}

		delete node;
	}
	//Node hat 2 Nachfolger
	else
	{
		TreeNode *prevMinNode = anker;
		TreeNode *minNode = findMinNode(node->getRight(), prevMinNode);

		//Min des RBT entnehmen
		if (prevMinNode == node)
		{
			prevMinNode->setRight(minNode->getRight());
		}
		else
		{
			prevMinNode->setLeft(minNode->getRight());
		}

		//Min an die Stelle des zu löschenden
		minNode->setLeft(node->getLeft());
		minNode->setRight(node->getRight());

		//prev von Node muss auf "minNode" zeigen
		if (anker == node)
		{
			anker = minNode;
		}
		else
		{
			if (prev->getNodePosID() < minNode->getNodePosID())
			{
				prev->setRight(minNode);
			}
			else
			{
				prev->setLeft(minNode);
			}
		}

		delete node;
	}
}

bool Tree::searchNode(std::string name)
{
	bool found = false;
	searchNodeByName(anker, name, found);
	if (!found)
	{
		std::cout << "Keine Fundstelle" << std::endl;
	}

	return found;
}

void Tree::printAll()
{
	std::cout << std::setw(4) << "ID |" << std::setw(13) << "Name |" << std::setw(8) << "Alter |" << std::setw(12) << "Einkommen |"
		<< std::setw(8) << "PLZ |" << std::setw(7) << "Pos\n";
	std::cout << "---+------------+-------+-----------+-------+-------\n";
	printAllRek(anker);
}