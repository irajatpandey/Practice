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

int getCount(LinkedList *t){
	if(t == NULL) return 0;

	return 1 + getCount(t -> next);
}

/*Best Solution*/
int getIntersectionPoint(LinkedList *head1, LinkedList *head2){
	
}


/* Hashing Solution */

int intersectionPoint(LinkedList *head1, LinkedList *head2){
	 
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

	 LinkedList* newNode; 
  
    // Addition of new nodes 
    LinkedList* head1 = new LinkedList(10); 
   
  
    LinkedList* head2 = new LinkedList(3); 
    
  
    newNode = new LinkedList(6); 
   
    head2->next = newNode; 
  
    newNode = new LinkedList(9); 
  
    head2->next->next = newNode; 
  
    newNode = new LinkedList(15); 
    
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new LinkedList(30); 
    
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
	
	cout << intersectionPoint(head1, head2);
	cout << getIntersectionPoint(head1, head2);

}