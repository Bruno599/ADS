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
	void printall();
	int NodePosCalc(int A, int E, int P);



};