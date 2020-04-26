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

void printList(LinkedList *head){
	while(head){
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

// Naive Solution
void eliminateDuplicateList(LinkedList *head){
	
	

}

void eliminateDuplicate(LinkedList *head){
	
}
int main(){

	LinkedList *head = NULL;

	int arr[] = {21, 43, 41, 21, 12, 11, 12};
	for(int i = 0; i < 7; i++)
		insert(&head, arr[i]);

	// eliminateDuplicate(head);
	// printList(head);

	eliminateDuplicateList(head);
	printList(head);


	

}