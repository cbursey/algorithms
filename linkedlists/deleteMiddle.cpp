
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
		Node* getMiddleNode(int k);
		void deleteMiddle(Node *middle);
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

Node* linkedList::getMiddleNode(int k){
	if (k < 1){
		cout << "must be a middle node" << endl;
		return NULL;
	}
	Node *curr = head;
	for (int i = 0; i < k; i++){
		curr = curr->next;
		if (curr->next == NULL){
			cout << "must be a middle node" << endl;
			return NULL;
		}
	}
	return curr;
}

void linkedList::deleteMiddle(Node *n){
	Node *next = n->next;
	while (next->next != NULL){
		n->data = next->data;
		next = next->next;
		n = n->next;
	}
	n->data = next->data;
	n->next = NULL;
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

	cout << "delete node #_" << endl;

	int k;
	cin >> k;

	Node *middle = list.getMiddleNode(k);
	if (middle != NULL) list.deleteMiddle(middle);

	list.printList();

	return 0;
}