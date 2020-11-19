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

LinkedList *reverseInKGroups(LinkedList *head, int k){
	if(head == NULL) return head;
	bool firstPass = true;
	LinkedList *curr = head;
	LinkedList *prevFirst = NULL;
	while(curr){
		LinkedList *prev = NULL;
		LinkedList *first = curr;
		int count = 0;
		while(curr != NULL and count ++ < k){
			LinkedList *next = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = next;

		}
		if(firstPass){
			firstPass = false;
			head = prev;
		}
		else{
			prevFirst -> next = prev;
		}
		prevFirst = first;

	}
	return head;

}
// Time Complexity: O(n) where n is the number of nodes in the given list.
LinkedList *k_reverse(LinkedList *head, int k){
	if(head == NULL) return head;
	LinkedList *curr = head;
	LinkedList *prev = NULL;
	LinkedList *next = NULL;
	int count = 0;
	while(curr and count++ < k){
		 next = curr -> next;
		 curr -> next = prev;
		 prev = curr;
		 curr = next;
	}
	if(next != NULL){
		LinkedList *restHead = k_reverse(next, k);
		head -> next = restHead;
	}
	return prev;
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

	int arr[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
	for(int i = 0; i < 9; i++)
		insert(&head, arr[i]);
	head = reverseInKGroups(head, 2);
	printList(head);

	

}