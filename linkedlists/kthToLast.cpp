
//Returns kth to last element of a list

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
		int kthToLast(int k);
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

int linkedList::kthToLast(int k){
	if (k < 1){
		cout << "k must be greater than 0" << endl;
		return -1;
	}
	int count = 0;
	Node *curr = head;
	while (curr != NULL){
		count++;
		curr = curr->next;
	}
	int moves = count - k;
	if (moves < 0){
		cout << "k must be less than size of list" << endl;
		return -1;
	}
	curr = head;
	for (int i = 0; i < moves; i++){
		curr = curr->next;
	}
	return curr->data;

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

	cout << "kth to last?" << endl;

	int k;
	cin >> k;
	cout << list.kthToLast(k) << endl;

	return 0;
}