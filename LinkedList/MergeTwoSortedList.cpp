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

	LinkedList *head = NULL;

	int arr[] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; i++)
		insert(&head, arr[i]);
	printList(head);

	head = mergeSort(head);
	printList(head);
	

}