#include "Tree.h"
#include <iomanip>


Tree::Tree()
{
	anker = nullptr;
	NodeIDCounter = 0;

};
void Tree::addNode(std::string N, int A, double E, int plz)
{
	int position = CalcPosID(A, plz, E);
	TreeNode * newNode = new TreeNode(position, NodeIDCounter, N, A, E, plz);
	newNode->setLeft(nullptr);
	newNode->setRight(nullptr);
	NodeIDCounter++;

	if (anker == nullptr)
	{
		anker = newNode;
	}
	else
	{
		TreeNode* hinterKnoten;
		searchnewNodePos(position, hinterKnoten);

		
		if (hinterKnoten->getRed() == true)
		{
			newNode->setRed(false);
		}



		if (position < hinterKnoten->getNodePosID())
		{

			hinterKnoten->setLeft(newNode);
		}
		else
		{
			hinterKnoten->setRight(newNode);
		}

	}
};


void Tree::getTBMin(TreeNode * tmp, TreeNode* &min, TreeNode* &Pmin)
{
	if (tmp->getLeft() == nullptr)
	{
		min = tmp;
	}
	while (tmp->getLeft() != nullptr)
	{
		Pmin = tmp;
		tmp = tmp->getLeft();
		min = tmp;
	}
	
}

bool Tree::searchNode(std::string N)
{
	bool gefunden = false;
	TreeNode* tmp = anker;
	Preorder(tmp, N, gefunden);
	if (gefunden == true)
	{
		return true;
	}
	else
	{
		return false;
	}
};
void Tree::printAll()
{
	std::cout << std::setw(4) << "ID |" << std::setw(13) << "Name |" << std::setw(8) << "Alter |" << std::setw(12) << "Einkommen |"
		<< std::setw(8) << "PLZ |" << std::setw(7) << "Pos\n";
	std::cout << "---+------------+-------+-----------+-------+-------\n";
	Preorder(this->anker);
};
void Tree::Preorder(TreeNode*tmp)
{
	tmp->print();
	if (tmp->getLeft() != nullptr) Preorder(tmp->getLeft());
	if (tmp->getRight() != nullptr) Preorder(tmp->getRight());
}

void Tree::Preorder(TreeNode*tmp, std::string N, bool &V)
{
	
	if (V != true)
	{
		if (N == tmp->getName())
		{
			V = true;
		}
	}
	
	if (tmp->getLeft() != nullptr) Preorder(tmp->getLeft(),N,V);
	if (tmp->getRight() != nullptr) Preorder(tmp->getRight(),N,V);
}

void Tree::searchNodePos(int ID, TreeNode* &pos, TreeNode* &Ppos)
{
	TreeNode* tmp = anker;
	while (true)
	{
		if (anker->getNodePosID() == ID)
		{
			Ppos = anker;
			pos = anker;
		}
		if (tmp->getNodePosID() != ID)
		{
			Ppos = tmp;
			if (ID < tmp->getNodePosID())
			{
				tmp = tmp->getLeft();
			}
			else
			{
				tmp = tmp->getRight();
			}
			pos = tmp;
		}
		else
		{
			break;
		}
	}

}
void Tree::searchnewNodePos(int ID,TreeNode* &pos)
{
	TreeNode* tmp = anker;
	while (true)
	{
		if (tmp != nullptr)
		{
			pos = tmp;
			if (ID < tmp->getNodePosID())
			{
				tmp = tmp->getLeft();
			}
			else
			{
				tmp = tmp->getRight();
			}

		}
		else
		{
			break;
		}
	}
	
}

int Tree::CalcPosID(int alter, int plz, double einkommen)
{
	return alter + plz + einkommen;
}

bool Tree::balanceTree(TreeNode* node)
{
	while (node->getLeft() != nullptr || node->getRight() != nullptr)
	{
		if (node->getLeft()->getRed() == 1 && node->getLeft()->getLeft()->getRed() == 1)        //rechtstrotation
		{
			rotateTreeRight(node, node->getLeft());
		}

		else if (node->getRight()->getRed() == 1 && node->getRight()->getRight()->getRed() == 1)  //Linksrotation
		{
			rotateTreeLeft(node, node->getRight());
		}

		else if (node->getLeft()->getRed() == 1 && node->getLeft()->getRight()->getRed() == 1)    //Links-, Rechtsrotation
		{
			rotateTreeLeft(node->getLeft(), node->getLeft()->getRight());
			rotateTreeRight(node, node->getLeft());
			
		}

		else if (node->getRight()->getRed() == 1 && node->getRight()->getLeft()->getRed() == 1)    //Rechts-, Linksrotation
		{
			rotateTreeRight(node->getRight(), node->getRight()->getLeft());
			rotateTreeLeft(node, node->getRight());
		}

		balanceTree(node->getLeft());
		balanceTree(node->getRight());
	}
}
/*
void Tree::balanceTree(TreeNode* Node)
{
	

	while (Node->getLeft() != nullptr || Node->getRight() != nullptr)
	{
		if (Node->getLeft()->getRed() == false && Node->getLeft()->getRed() == false)
		{

		}
		else
		{

		}

		balanceTree(Node->getLeft());
		balanceTree(Node->getRight());
	}
}
*/

void Tree::printLevelOrder()
{


}

bool Tree::rotateTreeRight(TreeNode* parent, TreeNode* child)
{
	TreeNode* pp = parent;
	TreeNode* p1 = child;
	TreeNode* p2;

	p2 = p1->getLeft();

	p1->setLeft(p2->getRight());

	p2->setRight(p1);

	if (pp->getNodePosID() > p2->getNodePosID())
	{
		pp->setLeft = p2;
	}
	else
	{
		pp->setRight = p2;
	}
}

bool Tree::rotateTreeLeft(TreeNode* parent, TreeNode* child)
{
	TreeNode* pp = parent;
	TreeNode* p1 = child;
	TreeNode* p2;

	p2 = p1->getRight();

	//pp->setRight(p1->getLeft());

	p1->setRight(p2->getLeft());

	p2->setLeft(p1);

	//pp->setLeft(p2);

	if(pp->getNodePosID() > p2->getNodePosID())
	{ 
		pp->setLeft(p2);
	}
	else
	{
		pp->setRight(p2);
	}

}

bool Tree::rotateTreeRightLeft(TreeNode* parent, TreeNode* child)
{
	TreeNode* pp = parent;
	TreeNode* p1 = child;
	TreeNode* p2;
	TreeNode* p3;

	//Rechtrotation P3 P2

	p3 = p2->getLeft();

	p2->setLeft(p3->getRight());

	p3->setRight(p2);

	//Linksrotation P2 P1

	p2 = p1->getRight();

	//pp->setRight(p1->getLeft());

	p1->setRight(p2->getLeft());

	p2->setLeft(p1);

	//pp->setLeft(p2);

	if (pp->getNodePosID() > p2->getNodePosID())
	{
		pp->setLeft(p2);
	}
	else
	{
		pp->setRight(p2);
	}

}

bool Tree::rotateTreeLeftRight(TreeNode* parent, TreeNode* child)
{
	TreeNode* pp = parent;
	TreeNode* p1 = child;
	TreeNode* p2;
	TreeNode* p3;

	//Linksrotation P3 P2

	p3 = p2->getRight();

	p2->setRight(p3->getLeft());

	p3->setLeft(p2);

	//Rechtrotation P2 P1

	p2 = p1->getLeft();

	p1->setLeft(p2->getRight());

	p2->setRight(p1);

	//pp->setLeft(p2);

	if (pp->getNodePosID() > p2->getNodePosID())
	{
		pp->setLeft(p2);
	}
	else
	{
		pp->setRight(p2);
	}

}