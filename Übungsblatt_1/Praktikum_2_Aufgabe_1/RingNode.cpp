#include "RingNode.h"

RingNode::RingNode()
{

};
RingNode::RingNode(int age, std::string descript, std::string data)
{

	setAge(age);
	setDescription(descript);
	setData(data);
	/*
	OldAge = age;
	Description = descript;
	SymbolicData = data;
	*/
};
int RingNode::getAge()
{
	return OldAge;
};
void RingNode::setAge(int age)
{
	OldAge = age;
};
std::string RingNode::getDescription()
{
	return Description;
};
void RingNode::setDescription(std::string descript) 
{
	Description = descript;
};
std::string RingNode::getData()
{
	return SymbolicData;
};
void RingNode::setData(std::string data)
{
	SymbolicData = data;
};
RingNode* RingNode::getNext() 
{
	return next;
};
void RingNode::setNext(RingNode* newnext)
{
	next = newnext;
};