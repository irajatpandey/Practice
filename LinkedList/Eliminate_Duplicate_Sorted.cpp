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
void eliminateDuplicate(LinkedList *head){
	

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

	int arr[] = {100, 90, 90, 80, 70, 60, 60, 50, 40, 40};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	eliminateDuplicate(head);
	printList(head);

	

}