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
bool isPalindromeBruteForce(LinkedList *head){
	if(!head) return true;
	vector<int> v;
	while(head){
		v.push_back(head -> data);
		head = head -> next;
	}

	for(int i = 0; i < v.size(); i++){
		if(v[i] != v[v.size() - i - 1])
			return false;
	}
	return true;
}
void reverse(LinkedList *&head){
	 LinkedList *curr = head;
	 LinkedList *next = NULL;
	 LinkedList *prev = NULL;

	 while(curr){
	 	next = curr -> next;
	 	curr -> next = prev;
	 	prev = curr;
	 	curr = next;
	 }
}
LinkedList *findMiddle(LinkedList *head, bool &odd){
	LinkedList *slow = head;
	LinkedList *fast = head;
	LinkedList *prev = NULL;

	while(fast and fast -> next){
		prev = slow;
		slow = slow -> next;
		fast = fast -> next -> next;
	}

	if(fast) odd = true;

	prev -> next = NULL;
	return slow;
}
bool compare(LinkedList *h1, LinkedList *h2){
	if(h1 == NULL and h2 == NULL) return true;
	while(h1 and h2){
		if(h1 -> data != h2 -> data)
			return false;
		h1 = h1 -> next;
		h2 = h2 -> next;
	}
	return true;
}
bool isPalindrome(LinkedList *head){
	if(head == NULL or head -> next == NULL) return true;
	 bool odd = false;
	 LinkedList *middle = findMiddle(head, odd);
	 if(odd) middle = middle -> next;
	 reverse(middle);

	 return compare(head, middle);

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
	if(isPalindromeBruteForce(head))
		cout << "Palindrome " << endl;
	else
		cout << "Not Palindrome " << endl;

	

}