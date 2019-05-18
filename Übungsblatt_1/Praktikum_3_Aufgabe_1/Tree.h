#pragma once
#include <iostream>
#include "TreeNode.h"


class Tree
{
private:
	TreeNode* anker;
	int NodeIDCounter;

	bool rotateTreeRight(TreeNode* parent, TreeNode* child);
	bool rotateTreeLeft(TreeNode* parent, TreeNode* child);

public:
	Tree();
	void addNode(std::string N, int A, double E, int plz);
	
	bool searchNode(std::string N);
	void printAll();

	void searchnewNodePos(int ID, TreeNode* &pos);
	void searchNodePos(int ID, TreeNode* &pos, TreeNode* &Ppos);
	int CalcPosID(int alter, int plz, double einkommen);
	void Preorder(TreeNode*tmp);
	void Preorder(TreeNode*tmp, std::string N, bool &V);
	friend TreeNode * get_anker(Tree& Tr);
	void getTBMin(TreeNode * tmp, TreeNode* &min, TreeNode* &Pmin);

	bool balanceTree(TreeNode* node);

};