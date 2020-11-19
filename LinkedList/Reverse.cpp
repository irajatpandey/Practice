#include<bits/stdc++.h>
using namespace std;

class LinkedList{
	public:
		int data;
		LinkedList *next;
	LinkedList(int x){
		data = x;
	}	
};

void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}
LinkedList* reverse(LinkedList *head){
	if(head == NULL or head -> next == NULL) return head;
	LinkedList *smallHead = reverse(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return smallHead;
}
/*Iterative Solution*/
LinkedList* reverseIterative(LinkedList *head){
	LinkedList *curr = head;
	LinkedList *prev = NULL;
	LinkedList *next = NULL;

	while(curr != NULL){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}


void printList(LinkedList *head){
	while(head){
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	printList(head);

	cout << "Revese LinkedList " << endl;
	head = reverse(head);
	printList(head);

	cout << "Revese LinkedList " << endl;
	head = reverseIterative(head);
	printList(head);
}