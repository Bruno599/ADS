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
			if (tmp2->getNodePosID < newNodePosID)
			{
				if (tmp2->getRight() == NULL)
				{
					tmp2->setRight(tmp);
					break;
				}
				tmp2 = tmp2->getRight();
				
				continue;
			}

			if (tmp2->getNodePosID > newNodePosID)
			{
				if (tmp2->getRight() == NULL)
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

};
bool Tree::searchNode(std::string N)
{

};
void Tree::printall()
{

};
int NodePosCalc(int A, int E, int P)
{
	//Alter + Einkommen + PLZ = Positionsindikator
	return A + E + P;
}