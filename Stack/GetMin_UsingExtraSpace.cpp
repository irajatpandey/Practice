#include<bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> ss;
void push_stack(int a){
     s.push(a);
     if(ss.size() == 0 or ss.top() >= a){
        ss.push(a);
     }
}
int pop_stack(){
    if(s.size() == 0)
        return -1;
    int ans = s.top();
    s.pop();

    if(ss.top() == ans) ss.pop();
    return ans;    
}
int getMin(){
    if(ss.empty()) return -1;
    return ss.top();
}
int main(){
    int arr[] = {18, 19, 29, 15, 16};
    for(auto it : arr){
        push_stack(it);
    }
    cout << getMin() << endl;
    cout << pop_stack() << endl;
    cout << getMin() << endl;
    cout << pop_stack() << endl;
    cout << getMin() << endl;

     

    return 0;
}