#pragma once
#include <iostream>
#include "TreeNode.h"


class Tree
{
private:
		TreeNode* anker;
		int NodeIDCounter;

public:
	Tree();
	void addNode(std::string N, int A, double E, int plz);
	void deleteNode(int NPID);
	bool searchNode(std::string N);
	void printAllRek(TreeNode* tmp);
	void printAll();
	int NodePosCalc(int A, double E, int P);
	bool Postorder(TreeNode* start, std::string Suchwort);
	TreeNode* searchNode(int NPID);
	void searchNodeByName(TreeNode* tmp, std::string name, bool &found);
	TreeNode* findMinNode(TreeNode* origin, TreeNode* &prev);
	//TreeNode* findMaxNode(TreeNode* origin, TreeNode* &prev);
	TreeNode* searchNodePosID(TreeNode* tmp, int nodePosID, TreeNode *&prev);
	TreeNode* TreeSuccessor(TreeNode* ziel);
	friend TreeNode * get_anker(Tree& Tr);


};