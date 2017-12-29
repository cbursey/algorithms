
//Partitions list around a number

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
		void partition(int n);
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

void linkedList::partition(int n){
	Node *curr = head;
	Node *smaller = NULL;
	Node *greater = NULL;
	Node *greaterHead;
	Node *smallerHead;
	while (curr != NULL){
		Node *temp = new Node;
		temp->data = curr->data;
		temp->next = NULL;
		if (curr->data >= n){
			if (greater == NULL){
				greater = temp;
				greaterHead = greater;
			} else {
				greater->next = temp;
				greater = greater->next;
			}
		} else {
			if (smaller == NULL){
				smaller = temp;
				smallerHead = smaller;
			} else {
				smaller->next = temp;
				smaller = smaller->next;
			}
		}
		curr = curr->next;
	}
	smaller->next = greaterHead;
	head = smallerHead;
}

int main(){
	linkedList list;

	list.addNode(8);
	list.addNode(5);
	list.addNode(3);
	list.addNode(7);
	list.addNode(1);
	list.addNode(9);
	list.addNode(6);
	list.addNode(4);
	list.addNode(12);
	list.printList();

	cout << "partition list around #_" << endl;

	int k;
	cin >> k;
	list.partition(k);

	list.printList();

	return 0;
}