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

/* Using Hashing*/
bool detectLoopHash(LinkedList *head){
	 set<LinkedList *> s;
	 while(head != NULL){
	 	if(s.find(head) != s.end())
	 		return true;
	 	s.insert(head);
	 	head = head -> next;
	 }
	 return false;
}

/* Best Solution */
bool detectLoop(LinkedList *head){
	LinkedList *fast = head;
	LinkedList *slow = head;

	while(fast -> next and fast -> next -> next){
		slow = slow -> next;
		fast = fast -> next -> next;
		if(slow == fast)
			return true;
	}	
 
  return false;	
}
void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {20, 4, 15, 10};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	head->next->next->next->next = head; 

	if(detectLoop(head)) cout << "true\n";
	else cout << "false\n";
	

	if(detectLoopHash(head)) cout << "true\n";
	else cout << "false\n";
	

}