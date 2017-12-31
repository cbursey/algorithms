
//adds 2 numbers represented by a list, both forwards and reverse

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
		void addToStart(int data);
		int length();
		Node* getHead();
		linkedList add(linkedList add);
		linkedList addReverse(linkedList add);

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

Node* linkedList::getHead(){
	return head;
}

linkedList linkedList::add(linkedList add){
	Node *currA = head;
	Node *currB = add.getHead();
	linkedList sum;
	int carry = 0;
	int valA;
	int valB;
	int data;
	while (currA != NULL || currB != NULL){
		valA = 0;
		valB = 0;
		if (currA != NULL){
			valA = currA->data;
			currA = currA->next;
		}
		if (currB != NULL){
			valB = currB->data;
			currB = currB->next;
		}
		data = valA + valB + carry;
		cout << data << endl;
		if (data >= 10){
			carry = 1;
			data = data - 10;
		} else {
			carry = 0;
		}
		sum.addNode(data);
	}
	if (carry > 0) sum.addNode(carry);
	return sum;
}

void linkedList::addToStart(int data){
	Node *newHead = new Node;
	newHead->data = data;
	newHead->next = head;
	head = newHead;
}

int reverseHelper(Node *headA, Node *headB, linkedList &sum){
	Node *currA = headA;
	Node *currB = headB;
	int carry = 0;
	int data = 0;
	if (headA->next != NULL || headB->next != NULL){
		if (headA->next != NULL) currA = currA->next;
		if (headB->next != NULL) currB = currB->next;
		carry = reverseHelper(currA, currB, sum);
		data = headA->data + headB->data + carry;
	} else {
		data = currA->data + currB->data;
	}
	if (data >= 10){
		data = data - 10;
		carry = 1;
	} else {
		carry = 0;
	}
	sum.addToStart(data);
	return carry;
}

int linkedList::length(){
	int result = 0;
	Node *curr = head;
	while (curr != NULL){
		result++;
		curr = curr->next;
	}
	return result;
}

void balanceZeros(linkedList &a, linkedList &b){
	int lengthA = a.length();
	int lengthB = b.length();
	int diff;
	if (lengthA > lengthB){
		diff = lengthA - lengthB;
		for (int i = 0; i < diff; i++){
			b.addToStart(0);
		}
	} else if (lengthB > lengthA){
		diff = lengthB - lengthA;
		for (int i = 0; i < diff; i++){
			a.addToStart(0);
		}
	}
}

linkedList linkedList::addReverse(linkedList add){
	balanceZeros(*this, add);
	linkedList sum;
	int carry = reverseHelper(head, add.getHead(), sum);
	if (carry > 0) sum.addToStart(carry);
	return sum;
	
}

int main(){
	linkedList listA;
	linkedList listB;

	listA.addNode(9);
	listA.addNode(1);
	listA.addNode(5);
	listA.addNode(1);

	listA.printList();

	listB.addNode(3);
	listB.addNode(4);
	listB.addNode(6);

	listB.printList();

	linkedList sum = listA.add(listB);
	linkedList sumReverse = listA.addReverse(listB);

	cout << "Sum: " << endl;
	sum.printList();

	cout << "Reverse sum: " << endl;
	sumReverse.printList();

	return 0;
}