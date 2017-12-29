
//Remove duplicates from a singly linked list

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
		void removeDups();
		void removeDupsNoBuffer();
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

void linkedList::removeDupsNoBuffer(){
	Node *curr = head;
	while (curr->next != NULL){
		Node *runner = curr;
		while (runner->next != NULL){
			if (runner->next->data == curr->data){
				runner->next = runner->next->next;
			} else {
				runner = runner->next;
			}
		}
		curr = curr->next;
	}
	return;
}

void linkedList::removeDups(){
	if (head == NULL) return;
	Node *curr = head;
	set<int> values;
	while (curr->next != NULL){
		if (values.count(curr->next->data)){
			curr->next = curr->next->next;
		} else {
			values.insert(curr->next->data);
			curr = curr->next;
		}
	}
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
	list.removeDups();
	list.printList();


	return 0;
}