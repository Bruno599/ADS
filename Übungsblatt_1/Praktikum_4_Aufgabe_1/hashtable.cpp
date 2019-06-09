#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size) {
	
	
	//*****************************
	// implement constructor here *
	//*****************************

	this->size = size;
	this->collisionCount = 0;
	this->elements = 0;
	hashTable = new vector<int>(size,-1);
	
	/*for (int i = 0; i == size; i++)
	{
		hashTable->push_back(-1);
	}
	*/
}

HashTable::~HashTable()
{
	//****************************
	// implement destructor here *
	//****************************

	delete hashTable;
}

int HashTable::hashValue(int item) {
	
	int index = item % this->size;
	//******************************************
	// implement calculation of hashindex here *
	//******************************************

	for (int i = 1; hashTable->at(index) != -1; i++)
	{
		collisionCount++;
		index = (item + i * i) % this->size;
	}

	//index = (item + collisionCount * collisionCount) % this->size;


	return index;
}

int HashTable::insert(int item) 
{
	
	
	//******************************************
	// implement insertion of new element here *
	//******************************************

	int position = hashValue(item);

	//if (this->hashTable->at(position) == -1)
	//{
		this->hashTable->at(position) = item;
		elements++;
	//}
	//else
	/*{
		collisionCount++;
		while (this->hashTable->at(position) != -1)
		{
			int position = hashValue(item);
			this->hashTable->at(position) = item;

			if (this->hashTable->at(position) != -1)
			{
				collisionCount++;
			}
		}
		this->elements++;
	}
	*/
	
	
	return 0; //dummy return
	
}


int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() {
	return this->collisionCount;
}

int HashTable::getSize() {
	return this->size;
}

int HashTable::getElements() {
	return this->elements;
}
