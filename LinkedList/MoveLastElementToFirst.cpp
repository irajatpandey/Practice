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

LinkedList *moveLastElementToFirst(LinkedList *head){
	if(head == NULL) return head;
	LinkedList *curr = head;
	LinkedList *prev = NULL;
	while(curr -> next){
		prev = curr;
		curr = curr -> next;
	}

	curr -> next = head;
	prev -> next = NULL;

	return curr;
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

	int arr[] = {8, 3, 1, 5, 2};
	for(int i = 0; i < 5; i++)
		insert(&head, arr[i]);
	head = moveLastElementToFirst(head);
	printList(head);

	

}