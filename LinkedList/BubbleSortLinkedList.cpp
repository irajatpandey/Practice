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

LinkedList *bubbleSort(LinkedList *head){
	if(!head) return head;
	for(LinkedList *i = head; i != NULL; i = i -> next){
		for(LinkedList *j = i -> next; j != NULL; j = j -> next){
			if(i -> data > j -> data)
				swap(i -> data, j -> data);
		}
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

	int arr[] = {8, 3, 1, 5, 2};
	for(int i = 0; i < 5; i++)
		insert(&head, arr[i]);
	head = bubbleSort(head);
	printList(head);

	

}