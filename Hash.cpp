// ConsoleApplication19.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>       
#include <string>
#include <stddef.h>

const int HASH_TABLE_SIZE = 50; //500,1000

int getHashIndexofKey(std::string value) {
	float hashIndex = 0.0;
	float sum = 0.0;
	int len = value.length();

	for (int k = 0; k < len; k++) {
		sum += (int)value[k];
		int polynomialIndex = pow(11, k);
		std::cout << "poly index: " << polynomialIndex << std::endl;
		hashIndex += (float)((int)value[k]) * polynomialIndex;
	}

	int index = (((int)fmodf(hashIndex, sum)*len) % HASH_TABLE_SIZE);

	return index;
}


class Node {
public:
	std::string value;
	Node *next;
};

class HashTable {
	int size = HASH_TABLE_SIZE;
	Node ** hashArray;
public:
	HashTable();
	void insert(std::string str);
	void lookup(std::string lookupValue);
};

HashTable::HashTable() {

	hashArray = new Node*[size];
	for (int i = 0; i < size; i++) {
		hashArray[i] = NULL;
	}
}

void HashTable::insert(std::string val) {
	int insertIndex = getHashIndexofKey(val);
	std::cout << "Inserting " << std::endl;
	Node* toInsert = new Node;
	toInsert->next = NULL;
	toInsert->value = val;

	if (hashArray[insertIndex] == NULL) {
		hashArray[insertIndex] = toInsert;
		std::cout << "Inserting with No collisions to " << insertIndex << std::endl;
	}
	else {
		int count=0;
		Node *finder = hashArray[insertIndex];
		while (finder->next != NULL) {
			finder = finder->next;
			count++;
		}
		finder->next = toInsert;
		std::cout << "Inserting with" << count << " collisions to " << insertIndex << std::endl;
	}
}

void HashTable::lookup(std::string lookupVal) {
	std::cout<<"lookup for value "<<lookupVal <<std::endl;
	int location=0;

	int lookupIndex = getHashIndexofKey(lookupVal);
	std::cout << "looking :" << std::endl;

	if (hashArray[lookupIndex] == NULL) {
		//hashArray[insertIndex] = toInsert;
		std::cout << "Lookup Value Not Found " << std::endl;
	}
	else {
		int count = 0;
		Node *finder = hashArray[lookupIndex];
		while (finder->value != lookupVal) {
			finder = finder->next;
			count++;
		}
		
		std::cout << "Found at " << lookupIndex << " location " <<count << std::endl;
	}
}


int main() {

	HashTable a;
	a.insert("anne");
	a.insert("mal");
	a.insert("del");
	a.insert("min");

	a.lookup("anne");
	a.lookup("kim");

	return 0;
}