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
	
}
/*Iterative Solution*/
LinkedList* reverseIterative(LinkedList *head){
	
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