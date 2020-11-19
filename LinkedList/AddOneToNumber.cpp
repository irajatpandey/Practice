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

LinkedList *addOneToLinkedList(LinkedList *head){
	if(head == NULL) return head;
	int sum = 0;

	head = reverse(head);
	printList(head);
	LinkedList *curr = head, *prev = NULL;
	int carry = 0;
	bool flag = true;
	while(curr){
		if(flag){
			sum = carry + curr -> data + 1;
			flag = false;
		}
		else{
			sum = carry + curr -> data;
			carry = 0;
		}
		if(sum == 10){
			curr -> data = 0;
			carry = 1;
		}
		else{
			curr -> data = sum;
		}
		prev = curr;
		curr = curr -> next;
	}
	if(carry){
		LinkedList *temp = new LinkedList(carry);
		prev -> next = temp;

	}
	head = reverse(head);
	return head;
}

void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}


int main(){

	LinkedList *head = NULL;

	int arr[] = {9, 9, 9, 9};
	for(int i = 3; i >= 0; i--)
		insert(&head, arr[i]);
	printList(head);
	head = addOneToLinkedList(head);
	printList(head);

	

}