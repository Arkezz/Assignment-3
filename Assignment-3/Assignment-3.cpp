#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

/*reate a function insertAfter that takes firstValue and secondValue. This function
searches for each occurrence of firstValue in the vector and insert the secondValue after
it in the same vector. The first and second values are taken from the user.
*/
void insertAfter(vector<int>& v, int firstValue, int secondValue) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == firstValue) {
			v.insert(v.begin() + i + 1, secondValue);
		}
	}
}

int main() {
	//Ask the user for n integers and store them in a vector of int
	int n;
	cout << "Enter the number of integers you want to enter: ";
	cin >> n;
	vector<int> v;
	cout << "Enter the integers: ";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	//Ask the user for two integers and insert the second integer after the first integer in the vector
	int firstValue, secondValue;
	cout << "Enter the first integer: ";
	cin >> firstValue;
	cout << "Enter the second integer: ";
	cin >> secondValue;
	insertAfter(v, firstValue, secondValue);
	//Display the vector
	cout << "The vector is: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;

	//Create a linked list based on the vector's elements
	LinkedList list;
	list.createList(v, list);

	//Display the list
	cout << "The list is: ";
	list.display();
	cout << endl;

	//Get the size of the list
	cout << "The size of the list is: " << list.getSize() << endl;

	//Get the sum of all the nodes
	cout << "The sum of all the nodes is: " << list.sum() << endl;

	//Get the count of each value in the list
	cout << "The count of each value in the list is: ";
	for (int i = 0; i < list.getSize(); i++) {
		if (i == 0) { // display the count of the first value in the list
			cout << list.getCount(v[i]) << " ";
		}
		else if (v[i] != v[i - 1]) { // only display the count of each value that is not a duplicate
			cout << list.getCount(v[i]) << " ";
		}
	}

	return 0;
}