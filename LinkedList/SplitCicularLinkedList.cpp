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
void splitIntoTwoHalves(LinkedList *head, LinkedList **h1, LinkedList **h2){
	if(!head) return;
	LinkedList *slow = head;
	LinkedList *fast = head;
	while(fast -> next != head and fast -> next -> next != head){
		fast = fast -> next -> next;
		slow = slow -> next;
	}

	if(fast -> next -> next == head)
		fast = fast -> next;
	*h1 = head;

	if(head -> next != head)
		*h2 = slow -> next;	

	fast -> next = slow -> next;
	slow -> next = head;
}
void printList(LinkedList *head)  
{  
    LinkedList *temp = head;  
    if(head != NULL)  
    {  
        cout << endl;  
        do {  
        cout << temp->data << " ";  
        temp = temp->next;  
        } while(temp != head);  
    } 

    cout << endl; 
}
int main(){

	LinkedList *head = NULL;

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i = n - 1; i >= 0; i--)
		insert(&head, arr[i]);
	LinkedList *temp = head;
	while(temp -> next){
		temp = temp -> next;
	}
	temp -> next = head;
	LinkedList *h1 = NULL, *h2 = NULL;
	printList(head);
	splitIntoTwoHalves(head, &h1, &h2);
	printList(h1);
	printList(h2);

}