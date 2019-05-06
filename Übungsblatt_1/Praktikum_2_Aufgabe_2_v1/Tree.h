
/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

using namespace std;

class Tree {

private:
	///////////////////////////////////////
	// Ihr Code hier:	
	TreeNode* anker;
	int nodeIDCounter;

	int calculateNodePosID(int age, int plz, double income);
	void searchNodeByName(TreeNode* tmp, std::string name, bool &found);
	TreeNode* searchNodePosID(TreeNode* tmp, int nodePosID, TreeNode *&prev);
	TreeNode* findMinNode(TreeNode* origin, TreeNode*& prev);
	void printAllRek(TreeNode* tmp);
	//
	////////////////////////////////////	

public:
	///////////////////////////////////////
	// Ihr Code hier:	
	Tree();
	void addNode(std::string name, int age, double income, int plz);
	void deleteNode(int nodePosID);
	bool searchNode(std::string name);
	void printAll();
	//
	////////////////////////////////////
	// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};