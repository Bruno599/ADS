#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <queue>


Tree::Tree()
{
	anker = nullptr;
	NodeIDCounter = 0;

};

void Tree::addNode(std::string N, int A, double E, int plz)
{
	int position = CalcPosID(A, plz, E);
	TreeNode * newNode = new TreeNode(position, NodeIDCounter, N, A, E, plz);

	if (anker == nullptr)
	{
		anker = newNode;
		NodeIDCounter++;
	}
	else
	{
		TreeNode* tmp = anker;

		if (anker->getLeft() == nullptr && anker->getRight() == nullptr)
		{
			if (newNode->getNodePosID() > anker->getNodePosID())
			{
				tmp->setRight(newNode);
			}
			else
			{
				tmp->setLeft(newNode);
			}
		}
		else if (anker->getLeft() != nullptr && newNode->getNodePosID() > anker->getNodePosID())
		{
			tmp->setRight(newNode);
		}
		else if (anker->getRight() != nullptr && newNode->getNodePosID() < anker->getNodePosID())
		{
			tmp->setLeft(newNode);
		}
		else
		{
			TreeNode* PhinterKnoten;
			TreeNode* hinterKnoten;
			searchnewNodePos(position, hinterKnoten);
			searchnewNodePos(hinterKnoten->getNodePosID(), PhinterKnoten);

			if (PhinterKnoten->getLeft() == hinterKnoten)
			{
				if (PhinterKnoten->getRight() == nullptr || PhinterKnoten->getRight()->getRed() == false)
				{
					if (hinterKnoten->getRight() == newNode)
					{
						rotateTreeLeft(PhinterKnoten, hinterKnoten);
						rotateTreeRight(PhinterKnoten, hinterKnoten);
					}
					else
					{
						rotateTreeRight(PhinterKnoten, hinterKnoten);
					}
				}
				else
				{
					PhinterKnoten->getRight()->setRed(false);
				}
			}
			else
			{
				if (PhinterKnoten->getLeft() == nullptr || PhinterKnoten->getLeft()->getRed() == false)
				{
					if (hinterKnoten->getRight() == newNode)
					{
						rotateTreeLeft(PhinterKnoten, hinterKnoten);
					}
					else
					{
						rotateTreeRight(hinterKnoten, newNode);
						rotateTreeLeft(PhinterKnoten, hinterKnoten);
					}
				}
				else
				{
					PhinterKnoten->getLeft()->setRed(false);
				}
			}
			//balanceTree(PhinterKnoten);
			balanceTree(anker);
		}



	}
}

/*
void Tree::addNode(std::string N, int A, double E, int plz)

{

	
	int position = CalcPosID(A, plz, E);
	TreeNode * newEntry = new TreeNode(position, NodeIDCounter, N, A, E, plz);


	if (anker == nullptr)

	{

		anker = newEntry;

		NodeIDCounter++;

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

					balanceTree(anker);

				}

			}



			if (tmp->getNodePosID() > newEntry->getNodePosID())

			{

				if (tmp->getLeft() == nullptr)

				{

					balanceTree(anker);

					tmp->setLeft(newEntry);

					balanceTree(anker);

					break;

				}

				tmp = tmp->getLeft();

			}

			else if (tmp->getNodePosID() < newEntry->getNodePosID())

			{

				if (tmp->getRight() == nullptr)

				{

					balanceTree(anker);

					tmp->setRight(newEntry);

					balanceTree(anker);

					break;

				}

				tmp = tmp->getRight();

			}


		}

		NodeIDCounter++;

	}



	anker->setRed(false);

}
/*
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
		anker->setRed(false);
	}
	else
	{
		TreeNode* PhinterKnoten;
		TreeNode* hinterKnoten;
		searchnewNodePos(position, hinterKnoten);
		searchnewNodePos(hinterKnoten->getNodePosID(), PhinterKnoten);

		if (position < hinterKnoten->getNodePosID())
		{

			hinterKnoten->setLeft(newNode);
		}
		else
		{
			hinterKnoten->setRight(newNode);
		}

		if (hinterKnoten == anker)
		{
			return;
		}

		/*
		if (hinterKnoten->getRed())
		{
			hinterKnoten->setRed(false);
		}
		

		if (PhinterKnoten->getLeft() == hinterKnoten)
		{
			if (PhinterKnoten->getRight() == nullptr || PhinterKnoten->getRight()->getRed() == false)
			{
				if (hinterKnoten->getRight() == newNode)
				{
					rotateTreeLeft(hinterKnoten, newNode);
					rotateTreeRight(PhinterKnoten, hinterKnoten);
				}
				else
				{
					rotateTreeRight(PhinterKnoten, hinterKnoten);
				}
			}
			else
			{
				PhinterKnoten->getRight()->setRed(false);
			}
		}
		else
		{
			if (PhinterKnoten->getLeft() == nullptr || PhinterKnoten->getLeft()->getRed() == false)
			{
				if (hinterKnoten->getRight() == newNode)
				{
					rotateTreeLeft(PhinterKnoten, hinterKnoten);
				}
				else
				{
					rotateTreeRight(hinterKnoten, newNode);
					rotateTreeLeft(PhinterKnoten, hinterKnoten);
				}
			}
			else
			{
				PhinterKnoten->getLeft()->setRed(false);
			}
		}
		//balanceTree(PhinterKnoten);
		balanceTree(anker);

	}
};

*/
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
	if (node != nullptr)
	{
		if (node->getRed())
		{
			if (node->getLeft() != nullptr && node->getLeft()->getRed())
			{
				if (node->getLeft()->getLeft() != nullptr && node->getLeft()->getLeft()->getRed())      //Rechtsrotation
				{
					rotateTreeRight(node, node->getLeft());
				}

				else if (node->getLeft()->getRight() != nullptr && node->getLeft()->getRight()->getRed())  //Links-, Rechtsrotation
				{
					rotateTreeLeft(node->getLeft(), node->getLeft()->getRight());
					rotateTreeRight(node, node->getLeft());
				}
			}

			else if (node->getRight() != nullptr && node->getRight()->getRed())
			{
				if (node->getRight()->getRight() != nullptr && node->getRight()->getRight()->getRed())    //Linksrotation
				{
					rotateTreeLeft(node, node->getRight());
				}

				else if (node->getRight()->getLeft() != nullptr && node->getRight()->getLeft()->getRed())  //Rechts-, Linksrotation
				{
					rotateTreeRight(node->getRight(), node->getRight()->getLeft());
					rotateTreeLeft(node, node->getRight());
				}
			}

			balanceTree(node->getLeft());
			balanceTree(node->getRight());
		}
	}

	return true;
}

void Tree::printLevelOrder()
{
	using namespace std;

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
/*
void Tree::printLevelOrder(TreeNode* node)
{
	std::cout << std::setw(4) << "ID |" << std::setw(13) << "Name |" << std::setw(8) << "Alter |" << std::setw(12) << "Einkommen |"
		<< std::setw(8) << "PLZ |" << std::setw(7) << "Pos\n";
	std::cout << "---+------------+-------+-----------+-------+-------\n";

	int h = heigh(node);
	int i;

	for (i = 1; i <= h; i++)
	{
		printGivenLevel(node, i);
	}
}

//Hilfsfunktionen
int Tree::heigh(TreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	else if (node == anker)
	{
		return 1;
	}

	else
	{
		int lheigh = heigh(node->getLeft());
		int rheigh = heigh(node->getRight());

		if (lheigh > rheigh)
		{
			return lheigh + 1;
		}

		else
		{
			return rheigh + 1;
		}
	}
}

void Tree::printGivenLevel(TreeNode* node, int level)
{
	if (node == nullptr)
	{
		return;
	}

	if (level == 1)
	{
		node->print();
	}

	else if (level > 1)
	{
		printGivenLevel(node->getLeft(), level - 1);
		printGivenLevel(node->getRight(), level - 1);
	}
}
/*void Tree::printLevelOrder()
{


}
*/
bool Tree::rotateTreeRight(TreeNode *Gp, TreeNode *Pp) {

	TreeNode* Ch = Pp->getLeft();

	if (Pp != anker) {

		Gp->setLeft(Ch);

	}

	else {

		anker = Ch;

	}

	Ch->setRight(Pp);

	Pp->setRed(true);

	Gp->setRed(false);

	Pp->setLeft(nullptr);

	return true;

}
/*
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
		pp->setLeft(p2);
	}
	else
	{
		pp->setRight(p2);
	}

	return true;
}
*/
bool Tree::rotateTreeLeft(TreeNode *Gp, TreeNode *Pp) {

	TreeNode* Ch = Pp->getRight();

	if (Pp != anker) {

		Ch->setRight(Gp);

	}

	else {

		anker = Ch;

	}

	Ch->setLeft(Pp);

	Pp->setRed(true);

	Gp->setRed(false);

	Pp->setRight(nullptr);

	return true;

}
/*
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



	return true;

}
*/

/*
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
*/