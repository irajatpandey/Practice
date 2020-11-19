#include<bits/stdc++.h>
using namespace std;
int evaluatePostfix(string &str)
{
    stack<int> s;
    
    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i])) s.push(str[i] - '0');
        else{
           
            int a = s.top(); s.pop(); 
            int b = s.top(); s.pop();
            switch(str[i]){
                case '+': s.push(b + a); break;
                case '-': s.push(b - a); break;
                case '*': s.push(b * a); break;
                case '/': s.push(b / a); break;
                default: break;
            }
            
        }
    }
    return s.top();
}
int main(){
	
	string exp = "231*+9-";  
    cout<<"postfix evaluation: "<< evaluatePostfix(exp);  
	return 0;
}

		