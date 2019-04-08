#pragma once

#include <string>

class FixedCapacityStackOfStrings 
{
private: 
	std::string* s; 
	int N;

public: 
	FixedCapacityStackOfStrings(int capacity) { s = new string[capacity]; N = 0; }
		bool isEmpty() { return N == 0; }
		void push(std::string item) { s[N++] = item; }
		std::string pop() { return s[--N]; }
};