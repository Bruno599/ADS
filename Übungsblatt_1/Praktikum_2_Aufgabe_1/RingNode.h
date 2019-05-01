#pragma once
#include <string>

class RingNode {

private:

	int OldAge;
	std::string Description;
	std::string SymbolicData;
	RingNode* next;

public:
	RingNode();
	RingNode(int age, std::string descript, std::string data);
	int getAge();
	void setAge(int age);
	std::string getDescription();
	void setDescription(std::string descript);
	std::string getData();
	void setData(std::string data);
	RingNode* getNext();
	void setNext(RingNode* newnext);

};