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

int lengthOfLoop(LinkedList *head){
    LinkedList *slow = head;
    LinkedList *fast = head;
    while(fast -> next and fast -> next -> next){
    	slow = slow -> next;
    	fast = fast -> next -> next;

    	if(slow == fast)
    		break;
    }
    int count = 1;
    while(slow -> next != fast){
    	count++;
    	slow = slow -> next;
    }

    return count;
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

	int arr[] = {20, 4, 15, 10};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	head->next->next->next->next = head; 
<<<<<<< HEAD
=======

	cout << lengthOfLoop(head) << endl;
>>>>>>> 84c80c075e409f2d9bebe12575b0355719ff53c4

	cout << lengthOfLoop(head) << endl;

}
