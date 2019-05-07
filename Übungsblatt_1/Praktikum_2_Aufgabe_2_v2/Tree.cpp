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
		searchnewNodePos(position, *&hinterKnoten);

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
void Tree::deleteNode(int NPID)
{
	if (anker == nullptr) return;
	/*if ( anker->getNodePosID() == NPID)
	{
		anker = nullptr;
		return;
	}
	*/

	TreeNode* Node;
	TreeNode* ParentNode;
	searchNodePos(NPID, Node, ParentNode);
	
	if (Node->getLeft() == nullptr && Node->getRight() == nullptr)
	{
		if (Node == this->anker)
		{
			this->anker = nullptr;
		}
		else if (ParentNode->getNodePosID() > Node->getNodePosID())
		{
			ParentNode->setLeft(nullptr);
		}
		else
		{
			ParentNode->setRight(nullptr);
		}
		//delete Node;
		Node = nullptr;
		return;
	}

	if (Node->getLeft() != nullptr && Node->getRight() == nullptr)
	{
		if (Node == anker)
		{
			anker = Node->getLeft();
		}
		else if (ParentNode->getNodePosID() > Node->getNodePosID())
		{
			ParentNode->setLeft(Node->getLeft());
		}
		else
		{
			ParentNode->setRight(Node->getLeft());
		}
		//delete Node;
		Node = nullptr;
		return;
	}

	if (Node->getLeft() == nullptr && Node->getRight() != nullptr)
	{
		if (anker == nullptr)
		{
			anker = Node->getRight();
		}
		else if (ParentNode->getNodePosID() > Node->getNodePosID())
		{
			ParentNode->setLeft(Node->getRight());
		}
		else
		{
			ParentNode->setRight(Node->getRight());
		}
		//delete Node;
		Node = nullptr;
		
		return;
	}

	if (Node->getLeft() != nullptr && Node->getRight() != nullptr)
	{
		TreeNode* minnoderight;
		TreeNode* Parentminnoderight = Node;
		getTBMin(Node->getRight(), minnoderight, Parentminnoderight);

		//Min des RBT entnehmen
		if (Parentminnoderight == Node)
		{
			Parentminnoderight->setRight(minnoderight->getRight());
		}
		else
		{
			Parentminnoderight->setLeft(minnoderight->getRight());
		}

		//Min an die Stelle des zu löschenden
		minnoderight->setLeft(Node->getLeft());
		minnoderight->setRight(Node->getRight());

		//prev von Node muss auf "minNode" zeigen
		if (anker == Node)
		{
			anker = minnoderight;
		}
		else
		{
			if (ParentNode->getNodePosID() < minnoderight->getNodePosID())
			{
				ParentNode->setRight(minnoderight);
			}
			else
			{
				ParentNode->setLeft(minnoderight);
			}
		}
		/*
		if (Node == anker)
		{
			anker = minnoderight;
		}
		

		if (ParentNode->getNodePosID() > Node->getNodePosID())
		{
			ParentNode->setLeft(minnoderight);
		}
		else
		{
			ParentNode->setRight(minnoderight);
		}

		if (Parentminnoderight != Node)
		{
			if (minnoderight->getRight() != nullptr)
			{
				Parentminnoderight->setLeft(minnoderight->getRight());
			}
			else
			{
				Parentminnoderight->setLeft(nullptr);
			}
		}
		minnoderight->setRight(Node->getRight());
		minnoderight->setLeft(Node->getLeft());
		*/
		//delete Node;
		Node == nullptr;
		
		return;
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