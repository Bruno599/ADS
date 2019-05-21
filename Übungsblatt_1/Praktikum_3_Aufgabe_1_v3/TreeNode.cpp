#include "TreeNode.h"
#include <iostream>
#include <string>
#include <iomanip>

void TreeNode::print() {
	std::cout << std::setw(3) << this->getNodeID();
	std::cout << "|";
	std::cout << std::setw(20) << this->getName();
	std::cout << "|";
	std::cout << std::setw(7) << this->getAlter();
	std::cout << "|";
	std::cout << std::setw(20) << this->getEinkommen();
	std::cout << "|";
	std::cout << std::setw(20) << this->getPLZ();
	std::cout << "|";
	std::cout << std::setw(20) << this->getNodePosID();
	std::cout << "|";
	std::cout << std::setw(10) << this->getRed() << std::endl;
}

double TreeNode::calcNodePosID(int age, int plz, double income) {
	return age + plz + income;
}