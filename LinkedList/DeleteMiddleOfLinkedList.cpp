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

LinkedList* deleteMiddleOfLinkedList(LinkedList *head){
	

	/*We will check for both even and odd case*/
	/*
	1 2 3 4 5		Answer = 3 		Condition for Odd length 	fast -> next != NULL 
	1 2 3 4 5 6		Answer = 4		Condition for even length 	fast -> next -> next != NULL	*/

<<<<<<< HEAD
	LinkedList *fast = head;
	LinkedList *slow = head;
	LinkedList *prev = head;
	while(fast -> next and fast -> next -> next){
		prev = slow;
		slow = slow -> next;
		fast = fast -> next -> next;

	}
	prev -> next = slow -> next;
	delete(slow);
	return head;
=======
	
>>>>>>> 84c80c075e409f2d9bebe12575b0355719ff53c4
		
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

	head = deleteMiddleOfLinkedList(head);
	printList(head);
	
	

<<<<<<< HEAD
}
=======
}
>>>>>>> 84c80c075e409f2d9bebe12575b0355719ff53c4
