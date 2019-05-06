#include "Tree.h"
#include <iomanip>

Tree::Tree()
{
	anker = nullptr;
	NodeIDCounter = 0;
}

/*void Tree::addNode(std::string name, int age, double income, int plz)
{
	TreeNode* newEntry = new TreeNode(NodePosCalc(age, plz, income), NodeIDCounter++, name, age, income, plz);

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
*/
void Tree::addNode(std::string N, int A, double E, int P)
{
	TreeNode* tmp = new TreeNode(NodePosCalc(A,E,P),NodeIDCounter,N,A,E,P); // A = Alter, E = Einkommen, P = PLZ, N = Name
	tmp->setLeft(NULL);
	tmp->setRight(NULL);
	NodeIDCounter++;

	if (anker == nullptr)
	{
		anker = tmp;
		//anker->setLeft(nullptr);
		//anker->setRight(nullptr);
	}
	else
	{
		int newNodePosID = NodePosCalc(A, E, P);
		TreeNode* tmp2 = anker;
		while (true)	//(tmp2->getLeft() != 0 || tmp2->getRight() != 0)
		{
			if (tmp2->getNodePosID() < newNodePosID)
			{
				if (tmp2->getRight() == NULL)
				{
					tmp2->setRight(tmp);
					break;
				}
				tmp2 = tmp2->getRight();
				
				continue;
			}

			if (tmp2->getNodePosID() > newNodePosID)
			{
				if (tmp2->getLeft() == NULL)
				{
					tmp2->setLeft(tmp);
					break;
				}
				tmp2 = tmp2->getLeft();
				
				continue;
			}

			//break;
		}
	}
};
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

void Tree::deleteNode(int NPID)
{
	TreeNode* tmp = searchNode(NPID);
	TreeNode* Ptmp = TreeSuccessor(tmp);
	TreeNode* temp = nullptr;

	if (tmp->getLeft() == NULL && tmp->getRight() == NULL)
	{
		//Ptmp = TreeSuccessor(tmp);
		if (Ptmp->getLeft()->getNodePosID() == tmp->getNodePosID())
		{
			Ptmp->setLeft(tmp->getLeft());
		}
		else
		{
			Ptmp->setRight(tmp->getRight());
		}
		delete tmp;
	}

	else if (tmp->getLeft() == NULL && tmp->getRight() != NULL)
	{
		//Ptmp = TreeSuccessor(tmp);

		if (Ptmp->getLeft()->getNodePosID() == tmp->getNodePosID())
		{
			Ptmp->setLeft(tmp->getRight());
		}
		else
		{
			Ptmp->setRight(tmp->getRight());
		}
		delete tmp;

	}

	else if (tmp->getLeft() != NULL && tmp->getRight() == NULL)
	{
		//Ptmp = TreeSuccessor(tmp);
		if (Ptmp->getLeft()->getNodePosID() == tmp->getNodePosID())
		{
			Ptmp->setLeft(tmp->getLeft());
		}
		else
		{
			Ptmp->setRight(tmp->getLeft());
		}
		delete tmp;

	}
	else
	{
		TreeNode *prevMinNode = anker;
		TreeNode *minNode = findMinNode(tmp->getRight(), prevMinNode);

		
		if (anker == tmp)
		{
			anker = minNode;
			if (minNode->getRight() != nullptr) prevMinNode->setLeft(minNode->getRight());
			if (tmp->getRight() != nullptr) minNode->setRight(tmp->getRight());
			if (tmp->getLeft() != nullptr) minNode->setLeft(tmp->getLeft());

		}
		else
		{
			if (minNode->getRight() != nullptr) prevMinNode->getRight()->setLeft(minNode->getRight());
			if (tmp->getRight() != nullptr) minNode->setRight(tmp->getRight());
			if (tmp->getLeft() != nullptr) minNode->setLeft(tmp->getLeft());

			if (Ptmp->getRight() == tmp)
			{
				Ptmp->setRight(minNode);
			}
			if (Ptmp->getLeft() == tmp)
			{
				Ptmp->setLeft(minNode);
			}
		}
		prevMinNode->setLeft(nullptr);
		
		/*
		//Min des RBT entnehmen
		if (prevMinNode == tmp)
		{
			prevMinNode->setRight(minNode->getRight());
		}
		else
		{
			prevMinNode->setLeft(minNode->getRight());
		}

		//Min an die Stelle des zu löschenden
		minNode->setLeft(tmp->getLeft());
		if (minNode != tmp->getRight())
		minNode->setRight(tmp->getRight());

		//prev von Node muss auf "minNode" zeigen
		if (anker == tmp)
		{
			anker = minNode;
		}
		else
		{
			if (Ptmp->getNodePosID() < minNode->getNodePosID())
			{
				Ptmp->setRight(minNode);
			}
			else
			{
				Ptmp->setLeft(minNode);
			}
		}
		*/
		delete tmp;
		
		/*
			Ptmp = TreeSuccessor(tmp);
			TreeNode* parent;
			findMinNode(tmp->getRight(), parent);
			Ptmp->setRight(parent->getLeft());
			parent->getLeft()->setRight(tmp->getRight());
			parent->getLeft()->setLeft(tmp->getLeft());
			parent->setLeft(nullptr);
			*/
		
			
		

		

	}

	/*
	if (tmp->getLeft() == NULL || tmp->getRight() == NULL)
	{
		Ptmp = tmp;
	}
	else
	{
		Ptmp = TreeSuccessor(tmp);
	}
	if (Ptmp->getLeft() != NULL)
	{
		temp = Ptmp->getLeft();
	}
	else
	{
		temp = Ptmp->getRight();
	}
	if (temp != NULL)
	{
		
	}
	*/
};
TreeNode* Tree::findMinNode(TreeNode* origin, TreeNode* &prev)
{
	TreeNode* minNode = origin;
	prev = origin;

	while (minNode->getLeft() != nullptr)
	{
		prev = minNode;
		minNode = minNode->getLeft();
	}

	return minNode;
}
/*TreeNode* Tree::findMaxNode(TreeNode* origin, TreeNode* &prev)
{
	TreeNode* maxNode = origin;
	prev = origin;

	while (maxNode->getRight() != nullptr)
	{
		prev = maxNode;
		maxNode = maxNode->getRight();
	}

	return maxNode;
}
*/
TreeNode* Tree::TreeSuccessor(TreeNode* ziel)
{
	TreeNode* tmp = anker;
	TreeNode* parent = nullptr;

	while (tmp != nullptr && tmp->getNodePosID() != ziel->getNodePosID())
	{
		if (ziel->getNodePosID() < tmp->getNodePosID())
		{
			parent = tmp;
			tmp = tmp->getLeft();
		}
		else
		{
			parent = tmp;
			tmp = tmp->getRight();
		}

	}
	return parent;
}
bool Tree::searchNode(std::string N)
{

		bool found = false;
		searchNodeByName(anker, N, found);
		if (!found)
		{
			std::cout << "Keine Fundstelle" << std::endl;
		}

		return found;
	/*
	if (this->Postorder(anker, N))
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	/*
	TreeNode* tmp = anker;
	while (tmp != NULL) 
	{
		if (tmp->getName == N) tmp->print();

		if (tmp->getLeft != NULL) tmp = tmp->getLeft;

		if (tmp->getRight != NULL) tmp = tmp->getRight;
	}
	*/
	
	/*while (tmp != nullptr && N != tmp->getName)
	{
		if ()
	}
	*/
};
TreeNode* Tree::searchNode(int NPID)
{
	
	
	TreeNode* tmp = anker;

	while (tmp != NULL && NPID != tmp->getNodePosID())
	{
		if (NPID < tmp->getNodePosID())
		{
			tmp = tmp->getLeft();
		}
		else
		{
			tmp = tmp->getRight();
		}
		
	}
	return tmp;
	
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
void Tree::printAllRek(TreeNode* tmp)
{
	if (tmp != nullptr)
	{
		tmp->print();
		printAllRek(tmp->getLeft());
		printAllRek(tmp->getRight());
	}
}
void Tree::printAll()
{
	std::cout << std::setw(4) << "ID |" << std::setw(13) << "Name |" << std::setw(8) << "Alter |" << std::setw(12) << "Einkommen |"
		<< std::setw(8) << "PLZ |" << std::setw(7) << "Pos\n";
	std::cout << "---+------------+-------+-----------+-------+-------\n";
	printAllRek(anker);
};
int Tree::NodePosCalc(int A, double E, int P)
{
	//Alter + Einkommen + PLZ = Positionsindikator
	return A + E + P;
}
bool Tree::Postorder(TreeNode* start, std::string Suchwort)
{
	TreeNode* tmp = start;
	if (tmp != NULL)
	{
		Postorder(tmp->getLeft(), Suchwort);
		Postorder(tmp->getRight(), Suchwort);
		
		if (tmp->getName() == Suchwort)
		{
			tmp->print();
			return true;
		}
		else
		{
			return false;
		}
	}
	//return false;
}