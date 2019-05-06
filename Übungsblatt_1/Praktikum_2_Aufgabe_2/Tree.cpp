#include "Tree.h"

Tree::Tree()
{
	anker = nullptr;
};
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
void Tree::deleteNode(int NPID)
{
	TreeNode* tmp = searchNode(NPID);
	TreeNode* Ptmp = TreeSuccessor(tmp);
	TreeNode* temp = nullptr;

	if (tmp->getLeft() == NULL && tmp->getRight() == NULL)
	{
		Ptmp = TreeSuccessor(tmp);
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

	else // (tmp->getLeft() == NULL && tmp->getRight() == NULL)
	{
		Ptmp = TreeSuccessor(tmp);

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
TreeNode* Tree::TreeSuccessor(TreeNode* ziel)
{
	TreeNode* tmp = anker;

	while (ziel->getNodePosID() != tmp->getLeft()->getNodePosID() || ziel->getNodePosID() != tmp->getRight()->getNodePosID())
	{
		if (ziel->getNodePosID() < tmp->getNodePosID())
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
bool Tree::searchNode(std::string N)
{
	if (this->Preorder(anker, N)) return true;
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
void Tree::printall()
{

};
int Tree::NodePosCalc(int A, double E, int P)
{
	//Alter + Einkommen + PLZ = Positionsindikator
	return A + E + P;
}
bool Tree::Preorder(TreeNode* start, std::string Suchwort)
{
	TreeNode* tmp = start;
	if (tmp != NULL)
	{
		Preorder(tmp->getLeft(), Suchwort);
		Preorder(tmp->getRight(), Suchwort);
		
		if (tmp->getName() == Suchwort)
		{
			tmp->print();
			return true;
		}
		else return false;
			
	}
	//return false;
}