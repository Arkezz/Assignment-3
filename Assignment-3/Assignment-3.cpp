#include <iostream>
//include vectors
#include <vector>
using namespace std;

//Queue class without using vectors
class Queue {
private:
	int* arr;
	int front;
	int rear;
	int size;
public:
	//default constructor
	Queue() {
		arr = new int[10];
		front = -1;
		rear = -1;
		size = 10;
	}
	Queue(int size) {
		this->size = size;
		front = -1;
		rear = -1;
		arr = new int[size];
	}
	//function to check if queue is empty
	bool isEmpty() {
		if (front == -1 && rear == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	//function to check if queue is full
	bool isFull() {
		if ((rear + 1) % size == front) {
			return true;
		}
		else {
			return false;
		}
	}
	//function to add element to queue
	void enqueue(int value) {
		if (isFull()) {
			cout << "Queue is full" << endl;
		}
		else if (isEmpty()) {
			front = 0;
			rear = 0;
			arr[rear] = value;
		}
		else {
			rear = (rear + 1) % size;
			arr[rear] = value;
		}
	}
	//function to remove element from queue
	void dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
		}
		else if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			front = (front + 1) % size;
		}
	}
	//function to display elements of queue
	void display() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
		}
		else {
			int i = front;
			while (i != rear) {
				cout << arr[i] << " ";
				i = (i + 1) % size;
			}
			cout << arr[rear] << endl;
		}
	}
};

//LinkedList class
class LinkedList {
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	//Add a node to the end of the list
	void addNode(int n) {
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
	void removeNode() {
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
	void insertNode(int pos, int n) {
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
	void deleteNode(int pos) {
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
	void display() {
		Node* temp = new Node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	//Get the size of the list
	int getSize() {
		return size;
	}

	LinkedList createList(int arr[], int size) {
		LinkedList list;
		for (int i = 0; i < size; i++) {
			list.addNode(arr[i]);
		}
		return list;
	}
	//Function that returns the sum of all the nodes
	int sum() {
		Node* temp = new Node;
		temp = head;
		int sum = 0;
		while (temp != NULL) {
			sum += temp->data;
			temp = temp->next;
		}
		return sum;
	}
};

int main() {
	/*Write a program that takes from the user n integers and stores them a vector of int.
• Then, create a function insertAfter that takes firstValue and secondValue. This function
searches for each occurrence of firstValue in the vector and insert the secondValue after
it in the same vector. The first and second values are taken from the use*/
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Enter the elements: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	LinkedList list;
	list = list.createList(arr, n);
	cout << "The list is: ";
	list.display();
	cout << endl;
	int firstValue, secondValue;
	cout << "Enter the first value: ";
	cin >> firstValue;
	cout << "Enter the second value: ";
	cin >> secondValue;
	//Insert the second value after the first value
	for (int i = 0; i < n; i++) {
		if (arr[i] == firstValue) {
			list.insertNode(i + 2, secondValue);
		}
	}
	cout << "The list after inserting the second value after the first value is: ";
	list.display();
	cout << endl;
	//Get the sum of all the nodes
	cout << "The sum of all the nodes is: " << list.sum() << endl;
	return 0;
}