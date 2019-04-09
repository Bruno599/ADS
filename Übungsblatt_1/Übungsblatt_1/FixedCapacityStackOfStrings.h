#pragma once

#include <string>

class FixedCapacityStackOfStrings 
{
private: 

	std::string* s; 
	int N;

public:
	/*FixedCapacityStackOfStrings()
	{

	}
	*/
	FixedCapacityStackOfStrings (int capacity) 
	{ 
	s = new std::string[capacity]; 
	N = 0; 
	}
	
	bool isEmpty() 
	{ 
		return N == 0; 
	}
		
	void push(std::string item) 
	{ 
		s[N++] = item; 
	}
		
	std::string pop() 
	{ 
		return s[--N]; 
	}

	bool isFULL()
	{
		return N == 5;
	}

	void print()
	{
		for (int p = N; p >= 0; p--)
		{
			std::cout << s[p] << std::endl;
		}
	}

	void resize(int length)
	{

	}
};