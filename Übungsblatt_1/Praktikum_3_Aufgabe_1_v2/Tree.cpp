/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <queue>

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

void Tree::printLevelOrder()
{
	queue<TreeNode*> q;
	if (anker != nullptr)
	{
		TreeNode* tmp;
		q.push(anker);
		cout << setw(4) << "ID |" << setw(13) << "Name |" << setw(8) << "Alter |" << setw(12) << "Einkommen |"
			<< setw(8) << "PLZ |" << setw(7) << "Pos\n";
		cout << "---+------------+-------+-----------+-------+-------\n";
		while (!q.empty())
		{
			tmp = q.front();
			q.pop();
			tmp->print();
			if (tmp->getLeft() != nullptr)
			{
				q.push(tmp->getLeft());
			}
			if (tmp->getRight() != nullptr)
			{
				q.push(tmp->getRight());
			}
		}
	}
}

Tree::Tree()
{
	anker = nullptr;
	nodeIDCounter = 0;
}

/*
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
		else if(newEntry->getNodePosID() > prev->getNodePosID())
		{
			prev->setRight(newEntry);
		}
	}
}*/

void Tree::addNode(std::string name, int age, double income, int plz)
{
	TreeNode* newEntry = new TreeNode(calculateNodePosID(age, plz, income), nodeIDCounter, name, age, income, plz);

	if (anker == nullptr)
	{
		anker = newEntry;
		nodeIDCounter++;
	}
	else
	{
		TreeNode* tmp = anker;

		while (true)
		{
			if (tmp->getLeft() != nullptr && tmp->getRight() != nullptr)
			{
				if (tmp->getLeft()->getRed() && tmp->getRight()->getRed())
				{
					tmp->setRed(true);
					tmp->getLeft()->setRed(false);
					tmp->getRight()->setRed(false);
					balanceTree();
				}
			}

			if (tmp->getNodePosID() > newEntry->getNodePosID())
			{
				if (tmp->getLeft() == nullptr)
				{
					balanceTree();
					tmp->setLeft(newEntry);
					balanceTree();
					break;
				}
				tmp = tmp->getLeft();
			}
			else if (tmp->getNodePosID() < newEntry->getNodePosID())
			{
				if (tmp->getRight() == nullptr)
				{
					balanceTree();
					tmp->setRight(newEntry);
					balanceTree();
					break;
				}
				tmp = tmp->getRight();
			}
			else if (tmp->getNodePosID() == newEntry->getNodePosID())
			{
				delete newEntry;
				--nodeIDCounter;
				break;
			}
		}
		nodeIDCounter++;
	}

	anker->setRed(false);
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
	cout << setw(4) << "ID |" << setw(13) << "Name |" << setw(8) << "Alter |" << setw(12) << "Einkommen |"
		<< setw(8) << "PLZ |" << setw(7) << "Pos\n";
	cout << "---+------------+-------+-----------+-------+-------\n";
	printAllRek(anker);
}

bool Tree::balanceTreeRek(TreeNode* prevPrev, TreeNode* prev, TreeNode* node, bool left)
{
	if (node == nullptr)
	{
		return true;
	}
	if (node->getRed())
	{
		if (node->getLeft() != nullptr && node->getLeft()->getRed())
		{
			if (left)
			{
				rotateTreeRight(prevPrev, prev);
				prev->setRed(true);
				node->setRed(false);
			}
			else
			{
				TreeNode* tmp = node->getLeft();
				rotateTreeRight(prev, node);
				rotateTreeLeft(prevPrev, prev);
				prev->setRed(true);
				tmp->setRed(false);
			}
		}
		else if (node->getRight() != nullptr && node->getRight()->getRed())
		{
			if (left)
			{
				TreeNode* tmp = node->getRight();
				rotateTreeLeft(prev, node);
				rotateTreeRight(prevPrev, prev);
				prev->setRed(true);
				tmp->setRed(false);
			}
			else
			{
				rotateTreeLeft(prevPrev, prev);
				prev->setRed(true);
				node->setRed(false);
			}
		}
	}

	balanceTreeRek(prev, node, node->getLeft(), true);
	balanceTreeRek(prev, node, node->getRight(), false);

	return true;
}

bool Tree::balanceTree()
{
	anker->setRed(false);

	if (anker->getLeft())
	{
		balanceTreeRek(nullptr, anker, anker->getLeft(), true);
	}
	if (anker->getRight())
	{
		balanceTreeRek(nullptr, anker, anker->getRight(), false);
	}
	return true;
}

bool Tree::rotateTreeLeft(TreeNode* parent, TreeNode* toRotate)
{
	TreeNode* rightChild = toRotate->getRight();

	// rechter Nachfolger von toRotate wird rightChild->GetLeft()
	toRotate->setRight(rightChild->getLeft());

	// linker Nachfolger von rightChild wird toRotate
	rightChild->setLeft(toRotate);

	if (parent != nullptr)
	{
		if (parent->getNodePosID() > rightChild->getNodePosID())
		{
			parent->setLeft(rightChild);
		}
		else
		{
			parent->setRight(rightChild);
		}
	}
	else
	{
		anker = rightChild;
	}

	return true;
}

bool Tree::rotateTreeRight(TreeNode* parent, TreeNode* toRotate)
{
	TreeNode* leftChild = toRotate->getLeft();

	// linker Nachfolger von toRotate wird leftChild->getRight()
	toRotate->setLeft(leftChild->getRight());

	// rechter Nachfolger von leftChild wird toRotate
	leftChild->setRight(toRotate);

	if (parent != nullptr)
	{
		if (parent->getNodePosID() > leftChild->getNodePosID())
		{
			parent->setLeft(leftChild);
		}
		else
		{
			parent->setRight(leftChild);
		}
	}
	else
	{
		anker = leftChild;
	}

	return true;
}