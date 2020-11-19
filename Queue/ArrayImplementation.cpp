#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
        int front, rear, size, capacity;
        int *arr;
        Queue(int c){
            capacity = c;
            front = -1;
            rear = -1;
            size = 0;
            arr = new int[capacity];
        }

        bool  isFull(){
            return rear == capacity;

        }
        bool isEmpty(){
            return front == rear;
        }

        void enqueue(int x){
            if(isFull()) return;
            if(front == - 1) front++;
            arr[++rear] = x;
            size++;
        }
        void dequeue(){
            if(isEmpty()) return;

            for(int i = 0; i < rear ; i++){
                arr[i] = arr[i+1];
                
            }
            
            rear--;
            size--;
        }  
        int sizeOfQueue(){
            return size;
        }

        void queueDisplay(){ 
            int i; 
            if (front == rear) { 
                printf("\nQueue is Empty\n"); 
                return; 
            } 
    
            // traverse front to rear and print elements 
            for (i = front; i <= rear; i++) { 
                printf(" %d <-- ", arr[i]); 
            } 
            cout << endl;
            return; 
    }
         
};




int main() {
  
    Queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.queueDisplay();
    
    q.dequeue();
    q.queueDisplay();

    cout << endl;
    cout << "Size of queue " << q.sizeOfQueue() << endl;
    return 0;
}