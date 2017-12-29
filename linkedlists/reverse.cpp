
//Deletes a node from list

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <set>

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
		void reverse();
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

void linkedList::reverse(){
	Node *curr = head;
	Node *next = NULL;
	Node *prev = NULL;
	while (curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return;
}

int main(){
	linkedList list;

	list.addNode(1);
	list.addNode(5);
	list.addNode(5);
	list.addNode(7);
	list.addNode(5);
	list.addNode(8);
	list.addNode(8);
	list.addNode(10);
	list.addNode(7);
	list.printList();

	cout << "reversing" << endl;

	list.reverse();
	list.printList();

	return 0;
}