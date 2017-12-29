
//Determines if a list is a palindrome

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class linkedList {
	private:
		Node *head;
	public:
		linkedList(){
			head = NULL;
		}
		void printList();
		void addNode(int data);
		bool palindrome();
};

void linkedList::printList(){
	Node *curr = head;
	while (curr != NULL){
		cout << "(" << curr->data << ") ";
		curr = curr->next;
	}
	cout << endl;
}

void linkedList::addNode(int data){
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL){
		head = temp;
		temp = NULL;
	} else {
		Node *curr = head;
		while (curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
	return;
}

bool linkedList::palindrome(){
	Node *fast = head->next;
	Node *slow = head;
	vector<int> values;
	while (fast != NULL && fast->next != NULL){
		values.push_back(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast != NULL) values.push_back(slow->data);
	slow = slow->next;
	int counter = values.size() - 1;
	while (slow != NULL && slow->next != NULL){
		if (slow->data != values[counter])
			return false;
		counter--;
		slow = slow->next;
	}
	return true;
}

int main(){
	linkedList listA;
	linkedList listB;
	linkedList listC;
	linkedList listD;
	linkedList listE;

	listA.addNode(8);
	listA.addNode(5);
	listA.addNode(3);
	listA.addNode(7);
	listA.addNode(1);
	listA.printList();
	cout << "Palindrome? " << listA.palindrome() << endl;

	listB.addNode(2);
	listB.addNode(7);
	listB.addNode(14);
	listB.addNode(6);
	listB.addNode(14);
	listB.addNode(7);
	listB.addNode(2);
	listB.printList();
	cout << "Palindrome? " << listB.palindrome() << endl;

	listC.addNode(8);
	listC.addNode(3);
	listC.addNode(5);
	listC.addNode(5);
	listC.addNode(3);
	listC.addNode(8);
	listC.printList();
	cout << "Palindrome? " << listC.palindrome() << endl;

	listD.addNode(10);
	listD.addNode(10);
	listD.printList();
	cout << "Palindrome? " << listD.palindrome() << endl; 

	listE.addNode(11);
	listE.printList();
	cout << "Palindrome? " << listE.palindrome() << endl; 

	return 0;
}