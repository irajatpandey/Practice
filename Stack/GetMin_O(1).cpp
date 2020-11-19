#include<bits/stdc++.h>
using namespace std;
int minEle = INT_MAX;
stack<int> s;
void push(int a){
    if(s.size() == 0){
        s.push(a);
        minEle = a;
    }

    else{
        if(a >= minEle){
            s.push(a);
        }
        else if(a < minEle){
            s.push(2 * a - minEle);
            minEle = a;
        }
    }
}

int pop(){
  int ans;
    if(s.size() == 0) return -1;
 
    else{
        int t = s.top();
        if(s.top() >= minEle){
            ans = s.top();
            
        } 
        else if(s.top() < minEle) {
            ans = minEle;
            minEle = 2 * minEle - t;
              
        }
        s.pop();
    }
    return ans;
}
int top(){
    if(s.top() >= minEle) return s.top();
    else{
        return minEle;
    }

}
int getMin(){
    if(s.empty()) return -1;
    return minEle;
}
int main(){
    
    push(18);
    push(19);
    push(29);
    cout << "Minimum Element " << getMin() << endl;
    push(15);
    push(16);
    cout << "Minimum Element " << getMin() << endl;
    cout << "popped Element " << pop() << endl;
    cout << "Minimum Element " << getMin() << endl;
    




    return 0;
}