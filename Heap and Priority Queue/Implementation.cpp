#include<bits/stdc++.h>
using namespace std;
class MinHeap{
    public:
        vector<int> v;
        MinHeap(){

        }

        bool isEmpty(){
            return v.size() == 0;
        }

        int getSize(){
            return v.size();
        }

        int getMinimum(){
            if(isEmpty()){
                return INT_MAX;
            }
            return v.at(0);
        }
        // O(logn) Time Complexity
        void insert(int x){
            v.push_back(x);
            int childIndex = v.size() - 1;
            while(childIndex > 0){
                int parentIndex = (childIndex - 1)/2;
                if(v.at(parentIndex) > v.at(childIndex)){
                    swap(v[parentIndex], v[childIndex]);
                    childIndex = parentIndex;
                }
                else{
                    break;
                }
            }   
        }


        int removeMinimum(){
            if(isEmpty()) return INT_MAX;
            int parentIndex = 0;
            int ans = v[0];
            swap(v[0], v[v.size() - 1] );
            v.pop_back();

            while(true){
                int leftChildIndex =  2*parentIndex + 1;
                int rightChildIndex = 2*parentIndex + 2;
                int minIndex = parentIndex;
                if(leftChildIndex < v.size() and v[minIndex] > v[leftChildIndex]){
                    minIndex = leftChildIndex;
                }
                if(rightChildIndex < v.size() and v[minIndex] > v[rightChildIndex]){
                    minIndex = rightChildIndex;
                }
                if(parentIndex == minIndex){
                    break;
                } 
                swap(v[parentIndex], v[minIndex]);
                parentIndex = minIndex;

            }
            return ans;
        }

};
int main(){

    MinHeap pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);


    cout << "Size of Heap : " << pq.getSize() << endl;
    cout << "Minimum Element : " << pq.getMinimum() << endl;

    while(!pq.isEmpty()){
        cout << pq.removeMinimum() << " ";
    }
    return 0;
}