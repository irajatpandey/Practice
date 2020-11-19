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

void pairWiseSwap(LinkedList *head){
	 while(head){
	 	swap(head -> data, head -> next -> data);
	 	head = head -> next -> next;
	 }
	
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

	int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, -11, -12};
	for(int i = 0; i < 12; i++)
		insert(&head, arr[i]);
	

	pairWiseSwap(head);
	printList(head);

}