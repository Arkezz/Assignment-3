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
//Modified addNode function that checks for duplicates and increments the count of the node if a duplicate is found
void LinkedList::addNode(int n) {
	Node* temp = new Node;
	temp->data = n;
	temp->next = NULL;

	//Check if the given value already exists in the list
	Node* current = head;
	while (current != NULL) {
		if (current->data == n) {
			//If a duplicate is found, increment the count of that node and return
			current->count++;
			return;
		}
		current = current->next;
	}

	//If the given value does not exist in the list, add it to the end of the list
	temp->count = 1;
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
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
	Node* temp = head;
	int count = 0;
	while (temp != NULL) {
		if (temp->data == n && temp->count > 0) {
			return temp->count;
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
//Modified createList function that adds the node to the list if it doesn't already exist
void LinkedList::createList(vector<int> v, LinkedList& list) {
	//Iterate through the elements in the vector
	for (int i = 0; i < v.size(); i++) {
		//Check if the current element already exists in the list
		bool exists = false;
		Node* current = head;
		while (current != NULL) {
			if (current->data == v[i]) {
				//If the element exists, increment the count of that node
				current->count++;
				exists = true;
				break;
			}
			current = current->next;
		}

		//If the element does not exist in the list, add it to the end of the list
		if (!exists) {
			list.addNode(v[i]);
		}
	}
}

//Function that calculates the sum of the elements in the linked list
int LinkedList::sum() {
	int total = 0;
	Node* temp = head;
	while (temp != NULL) {
		//Add the value of the current node to the total and then add the count of the node to account for duplicates
		total += temp->data * temp->count;
		temp = temp->next;
	}
	return total;
}