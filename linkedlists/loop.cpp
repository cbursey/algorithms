
//detects loop in a linkedList

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
		void createLoop();
		Node* detectLoop();

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

void linkedList::createLoop(){
	Node *curr = head;
	while (curr->next->next != NULL){
		curr = curr->next;
	}
	curr->next = head->next->next;
	return;
}

Node* linkedList::detectLoop(){
	Node *slow = head;
	Node *fast = head;
	while (true){
		slow = slow->next;
		fast = fast->next->next;
		if (fast == NULL || fast->next == NULL) return NULL; //no loop
		if (slow == fast) break;
	}
	int counter = 1; //loop size
	fast = slow->next;
	while (fast != slow){
		fast = fast->next;
		counter++;
	}
	cout << "loop size: " << counter << endl;
	fast = head;
	slow = head;
	for (int i = 0; i < counter; i++){
		fast = fast->next;
	}
	Node *corrupt = fast;
	while (fast != slow){
		corrupt = fast;
		fast = fast->next;
		slow = slow->next;
	}
	return corrupt;


}

int main(){
	linkedList listA;
	linkedList listB;

	listA.addNode(5);
	listA.addNode(1);
	listA.addNode(7);
	listA.addNode(1);
	listA.addNode(9);
	listA.addNode(2);
	listA.addNode(8);

	listA.printList();

	cout << "creating loop..." << endl;
	listA.createLoop();


	Node* corruptA = listA.detectLoop();
	int corruptValA = corruptA == NULL ? -1 : corruptA->data;

	cout << "corrupt node: " << corruptValA << endl;

	listB.addNode(3);
	listB.addNode(4);
	listB.addNode(6);
	listB.addNode(1);

	listB.printList();

	Node* corruptB = listB.detectLoop();
	int corruptValB = corruptB == NULL ? -1 : corruptB->data;

	cout << "corrupt node: " << corruptValB << endl;

	return 0;
}