#pragma once
#include <iostream>
#include <vector>
using namespace std;
//Linked list class declaration from main
class LinkedList {
private:
	// contains the value of the number and its number of occurences
	struct Node {
		int data;
		int count;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	//Default constructor
	LinkedList();
	//Destructor
	~LinkedList();
	//Add a node to the end of the list
	void addNode(int n);
	//Remove a node from the end of the list
	void removeNode();
	//Insert a node at a specific position
	void insertNode(int pos, int n);
	//Delete a node at a specific position
	void deleteNode(int pos);
	//Display the list
	void display() const;
	//Get the size of the list
	int getSize() const;
	//Get count of a specific node
	int getCount(int n) const;
	//Get node at a specific position
	int getNode(int pos) const;
	//Function that creates a linked list based on the vector's elements. This function should then return the linked list by reference
	void createList(vector<int> v, LinkedList& list);
	//Function that returns the sum of all the nodes
	int sum();
};