/*************************************************
* ADS Praktikum 2.2
* TreeNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <string>

TreeNode::TreeNode(int nodePosID, int NodeID, std::string name, int age, double income, int plz)
{
	this->nodePosID = nodePosID;
	this->nodeID = NodeID;
	this->red = true;
	this->name = name;
	this->age = age;
	this->income = income;
	this->plz = plz;
	this->left = nullptr;
	this->right = nullptr;
}

int TreeNode::getNodePosID()
{
	return this->nodePosID;
}

int TreeNode::getNodeID()
{
	return this->nodeID;
}

std::string TreeNode::getName()
{
	return this->name;
}

void TreeNode::setName(std::string name)
{
	this->name = name;
}

int TreeNode::getAlter()
{
	return this->age;
}

void TreeNode::setAlter(int age)
{
	this->age = age;
}

double TreeNode::getEinkommen()
{
	return this->income;
}

void TreeNode::setEinkommen(double income)
{
	this->income = income;
}

int TreeNode::getPLZ()
{
	return this->plz;
}

void TreeNode::setPLZ(int plz)
{
	this->plz = plz;
}

TreeNode* TreeNode::getLeft()
{
	return this->left;
}

TreeNode* TreeNode::getRight()
{
	return this->right;
}

void TreeNode::setLeft(TreeNode* leftNode)
{
	this->left = leftNode;
}

void TreeNode::setRight(TreeNode* rightNode)
{
	this->right = rightNode;
}

void TreeNode::print()
{
	std::cout << std::setw(3) << nodeID << "|" << std::setw(12) << name << "|" << std::setw(7) << age << "|" << std::setw(11) << income << "|" << std::setw(7) << plz << "|" << std::setw(6) << nodePosID << "\n";
}

bool TreeNode::getRed()
{
	return red;
}

void TreeNode::setRed(bool red)
{
	this->red = red;
}