#include<bits/stdc++.h>
using namespace std;

class LinkedList{
	public:
		int data;
		LinkedList *next;
	LinkedList(int x){
		data = x;
		next = NULL;
	}	
};
int getLength(LinkedList *head){
	if(!head) return 0;
	return 1 + getLength(head -> next);
}
LinkedList *reverse(LinkedList *&head){
	 LinkedList *curr = head;
	 LinkedList *next = NULL;
	 LinkedList *prev = NULL;

	 while(curr){
	 	next = curr -> next;
	 	curr -> next = prev;
	 	prev = curr;
	 	curr = next;
	 }
	 return prev;
}
void printList(LinkedList *head){
	while(head){
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

LinkedList *addTwoLinkedList(LinkedList *first, LinkedList *second){
	int sum = 0, carry = 0;
	LinkedList *newLinkedList = NULL;
	LinkedList *prev = NULL;
	while(first != NULL and second != NULL){
		sum = carry + (first != NULL ? first -> data : 0) + (second != NULL ? second -> data : 0);
		carry = sum / 10;
		LinkedList *node = new LinkedList(sum % 10);

		if(newLinkedList == NULL)
			newLinkedList = node;
		else
			prev -> next = node;
		prev = node;
		if(first) first = first -> next;
		if(second) second = second-> next;
	}
	
	if(carry != 0)
		prev -> next = new LinkedList(carry);
	return newLinkedList;
}

void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}


int main(){

	LinkedList *first = NULL;
	LinkedList *second = NULL;

	int a[] = {1, 0, 0, 1};
	for(int i = 3; i >= 0; i--)
		insert(&first, a[i]);
	int b[] = {5, 0, 0, 5};
	
	for(int i = 3; i >= 0; i--){
		insert(&second, b[i]);
	}
	LinkedList *finalList = addTwoLinkedList(first, second);
	printList(finalList);

	

}