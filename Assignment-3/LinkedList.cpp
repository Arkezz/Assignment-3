#include "LinkedList.h"
#include <vector>
//Linked list class implementation
//Default constructor
LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}
//Destructor
LinkedList::~LinkedList() {
	Node* temp = head;
	while (temp != NULL) {
		head = head->next;
		delete temp;
		temp = head;
	}
}
//Add a node to the end of the list
void LinkedList::addNode(int n) {
	Node* temp = new Node;
	temp->data = n;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
	size++;
}

//Remove a node from the end of the list
void LinkedList::removeNode() {
	Node* current = new Node;
	Node* previous = new Node;
	current = head;
	while (current->next != NULL) {
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = NULL;
	delete current;
	size--;
}

//Insert a node at a specific position
void LinkedList::insertNode(int pos, int n) {
	Node* prev = new Node;
	Node* curr = new Node;
	Node* temp = new Node;
	curr = head;
	for (int i = 1; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}
	temp->data = n;
	prev->next = temp;
	temp->next = curr;
	size++;
}

//Delete a node at a specific position
void LinkedList::deleteNode(int pos) {
	Node* curr = new Node;
	Node* prev = new Node;
	curr = head;
	for (int i = 1; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	size--;
}

//Display the list
void LinkedList::display() const {
	Node* temp = new Node;
	temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

//Return the size of the list
int LinkedList::getSize() const {
	return size;
}

//Get count of a specific node
int LinkedList::getCount(int n) const {
	Node* temp = new Node;
	temp = head;
	int count = 0;
	while (temp != NULL) {
		if (temp->data == n) {
			count++;
		}
		temp = temp->next;
	}
	return count;
}

//Get node at a specific position
int LinkedList::getNode(int pos) const {
	Node* current = new Node;
	Node* previous = new Node;
	current = head;
	for (int i = 1; i < pos; i++) {
		previous = current;
		current = current->next;
	}
	return current->data;
}

//Function that creates a linked list based on the vector's elements. This function should then return the linked list by reference
void LinkedList::createList(vector<int> v, LinkedList& list) {
	for (int i = 0; i < v.size(); i++) {
		list.addNode(v[i]);
		//Increment the count if repeated
		Node* temp = new Node;
		temp = head;
		while (temp != NULL) {
			if (temp->data == v[i]) {
				temp->count++;
			}
			temp = temp->next;
		}
	}
}
//Function that returns the sum of all the nodes
int LinkedList::sum() {
	int sum = 0;
	Node* temp = new Node;
	temp = head;
	while (temp != NULL) {
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}