#include<bits/stdc++.h>
using namespace std;
/* string removeDuplicates(string S) {
        string a;
        for (auto& c : S) 
            if (a.size() && a.back() == c){
                 a.pop_back();
                 
            }
            else a.push_back(c);
        return a;
    } */
string removeDuplicates(string str) {
    stack<char> s;
    string ans = "";
    for(auto it : str){
        if(s.empty()) s.push(it);
        else if(s.top() == it) s.pop();
        else s.push(it);
    }
       
        
    while(!s.empty()){
        ans.push_back(s.top()); 
        s.pop();
        }
    return ans;
    }
int main(){
    string str = "abbaca";
    cout << removeDuplicates(str);

}