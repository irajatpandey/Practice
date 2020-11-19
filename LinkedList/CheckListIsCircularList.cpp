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

bool checkCircularLinkedList(LinkedList *head){
	LinkedList *temp = head -> next;
	while(temp){
		if(temp == head)
			return true;
		temp = temp -> next;
	}
	return false;
}



void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}

void printList(LinkedList *head){
	if(!head) return;
	LinkedList *temp = head;
	head = head -> next;
	while(head){
		if(head != temp){
			cout << head -> data << " ";
			head = head -> next;
		}
		else
			break;
	}
	cout << endl;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {1, 2, 3, 2, 1};
	for(int i = 0; i < 5; i++)
		insert(&head, arr[i]);
	LinkedList *temp = head;
	while(temp -> next){
		temp = temp -> next;
	}
	temp -> next = head;
	if(checkCircularLinkedList(head))
		cout << "Yes";
	else
		cout << "No";
	
	printList(head);
}