#pragma once
#include <iostream>
#include <string>

class TreeNode
{
private:
	int NodePosID;
	int NodeID;
	std::string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	TreeNode* left;
	TreeNode*right;

public:
	TreeNode
	(int posID, int nodeID, std::string name, 
	 int alter, double einkommen, int plz);
	int getNodePosID();
	int getNodeID();
	std::string getName();
	void setName(std::string name);
	int getAlter();
	void setAlter(int alter);
	double getEinkommen();
	void setEinkommen(double einkommen);
	int getPLZ();
	void setPLZ(int plz);

	TreeNode* getLeft();
	void setLeft(TreeNode* newleft);
	TreeNode* getRight();
	void setRight(TreeNode* newright);
	void print();

	
	
};