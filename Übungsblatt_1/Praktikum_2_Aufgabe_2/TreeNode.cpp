#include "TreeNode.h"
#include <iomanip>

TreeNode::TreeNode(int posID, int nodeID, std::string name, int alter, double einkommen, int plz)
{
	NodePosID = posID;
	NodeID = nodeID;
	Name = name;
	Alter = alter;
	Einkommen = einkommen;
	PLZ = plz;
};
int TreeNode::getNodePosID()
{
	return NodePosID;
};
int TreeNode::getNodeID()
{
	return NodeID;
};
std::string TreeNode::getName()
{
	return Name;
};
void TreeNode::setName(std::string name)
{
	Name = name;
};
int TreeNode::getAlter()
{
	return Alter;
};
void TreeNode::setAlter(int alter) 
{
	Alter = alter;
};
double TreeNode::getEinkommen()
{
	return Einkommen;
};
void TreeNode::setEinkommen(double einkommen) 
{
	Einkommen = einkommen;
};
int TreeNode::getPLZ()
{
	return PLZ;
};
void TreeNode::setPLZ(int plz)
{
	PLZ = plz;
};

TreeNode* TreeNode::getLeft()
{
	return this->left;
};
void TreeNode::setLeft(TreeNode* newleft)
{
	this->left = newleft;
};
TreeNode* TreeNode::getRight() 
{
	return this->right;
};
void TreeNode::setRight(TreeNode* newright) 
{
	this->right = newright;
};
void TreeNode::print()
{
	std::cout << std::setw(3) << NodeID << "|" << std::setw(12) << Name << "|" << std::setw(7) << Alter << "|" << std::setw(11) << Einkommen << "|" << std::setw(7) << PLZ << "|" << std::setw(6) << NodePosID << "\n";
};