#include<bits/stdc++.h>
using namespace std;

class Queue{
     
    public:
    int data;
    Queue *next;
     Queue(int x){
         data = x;
         next = NULL;
     }
};

class Node{
    public:
    Queue *rear;
    Queue *front;
    Node(){
        front = rear = NULL;
    }
    void enqueue(int x){
        Queue *temp = new Queue(x);
        if(rear == NULL){
            front = rear = temp;
            return;
        }

        rear -> next = temp;
        rear = temp;
    }
    void dequeue(){
        if(front == NULL) return;
        Queue *temp = front;
        front = front -> next;
        delete temp;
    
    }

    void display(){
        Queue * temp = front;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }



};



int main() {
    
    Node q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}