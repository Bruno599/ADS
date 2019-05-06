
/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode {

private:
	///////////////////////////////////////
	// Ihr Code hier:	
	int nodePosID;
	int nodeID;
	std::string name;
	int age;
	double income;
	int plz;
	TreeNode* left;
	TreeNode* right;
	//
	////////////////////////////////////

public:
	///////////////////////////////////////
	// Ihr Code hier:
	TreeNode(int nodePosID, int NodeID, std::string name, int age, double income, int plz);
	int getNodePosID();
	int getNodeID();
	std::string getName();
	void setName(std::string name);
	int getAlter();
	void setAlter(int age);
	double getEinkommen();
	void setEinkommen(double income);
	int getPLZ();
	void setPLZ(int plz);

	TreeNode* getLeft();
	TreeNode* getRight();
	void setLeft(TreeNode* leftNode);
	void setRight(TreeNode* rightNode);
	void print();
	//
	////////////////////////////////////
};