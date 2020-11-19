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
int getLength(LinkedList *head){
	if(!head) return 0;
	return 1 + getLength(head -> next);
}
int printNthFromLast(LinkedList *head, int n){
	LinkedList *mainPointer = head;
	LinkedList *referencePointer = head;

	for(int i = 0; i < n; i++){
		referencePointer = referencePointer -> next;
	}
	while(referencePointer != NULL){
		mainPointer = mainPointer -> next;
		referencePointer = referencePointer -> next;
	}
	return mainPointer -> data;
}
LinkedList *NthElementFromEndOfTheList(LinkedList *head, int n){
	if(!head) return NULL;
	int sizeOfList = getLength(head);

	for(int i = 0; i < sizeOfList - n; i++){
		head = head -> next;
	}
	return head;
}
void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
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

	LinkedList *h = NthElementFromEndOfTheList(head, 2);
	cout << h -> data << endl;

	cout << printNthFromLast(head, 2);
	

}