#include<bits/stdc++.h>
using namespace std;
class Stack{
public:
	int top;
	int *arr;

	Stack(){
		top =  -1;
		arr = new int[50];
	}
 bool isEmpty(){
	return top == -1;
  }
 bool isFull(){
 	return top == 50;
 }

 void push(int x){
 	if(!isFull())
 		arr[++top] = x;
 }

 void pop(){
 	if(!isEmpty())
 		top--;
 }
 void topOfStack(){
    cout << arr[top] << endl;
 }

};

int main(){


	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	s.topOfStack();
	s.pop();
	s.topOfStack();
}