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

LinkedList *merge(LinkedList *head1, LinkedList *head2){
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

	LinkedList *head1 = NULL;
	LinkedList *head2 = NULL;
	LinkedList *head = NULL;

	int arr1[] = {9, 7, 5, 3, 1};
	int arr2[] = {8, 6, 4, 2, 0};
	for(int i = 0; i < 5; i++)
		insert(&head1, arr1[i]);
	for(int i = 0; i < 5; i++)
		insert(&head2, arr2[i]);

	head = merge(head1, head2);
	printList(head);
	
	

}
