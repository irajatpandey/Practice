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

void printList(LinkedList *head){
	while(head){
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

// Naive Solution
void eliminateDuplicateList(LinkedList *head){
	LinkedList *curr = head;
	while(curr and curr -> next != NULL){
		LinkedList *temp = curr;
		while(temp -> next){
			if(curr -> data == temp -> next -> data){
				LinkedList *next = temp -> next;
				temp -> next = temp -> next -> next;
				delete(next);
			}
			else
				temp = temp -> next;
		}
		curr = curr -> next;
	}

}

void eliminateDuplicate(LinkedList *head){
	unordered_set<int> s;
	LinkedList *prev = head;
	LinkedList *curr = head;
	while(curr){
		if(s.find(curr -> data) != s.end()){
			prev -> next = curr -> next;
			delete(curr);
		}
		else{
			s.insert(curr -> data);
			prev = curr;
		}
		curr = prev -> next;
	}
}
int main(){

	LinkedList *head = NULL;

	int arr[] = {21, 43, 41, 21, 12, 11, 12};
	for(int i = 0; i < 7; i++)
		insert(&head, arr[i]);

	eliminateDuplicate(head);
	printList(head);

	eliminateDuplicateList(head);
	printList(head);


	

}