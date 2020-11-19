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


bool isPalindrome(LinkedList **left, LinkedList *right){
	if(right == NULL)
		return true;
 	bool flag = isPalindrome(left, right -> next);
 	if(flag == false)
 		return false;
 	bool check_palindrome = ((*left) -> data == right -> data);
 	*left = (*left) -> next;
 	return check_palindrome;
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

	int arr[] = {1, 2, 3, 2, 1};
	for(int i = 0; i < 5; i++)
		insert(&head, arr[i]);
	if(isPalindrome(&head, head))
		cout << "Palindrome " << endl;
	else
		cout << "Not Palindrome " << endl;

	

}