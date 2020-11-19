#include<bits/stdc++.h>
using namespace std;
bool match(char b , char a){
	return (a == '(' and  b == ')') or (a == '{' and b == '}') or (a == '[' and b == ']'); 
}
bool isBalanced(string str){
	stack<char> s;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '(' or str[i] == '{' or str[i] == '[')
			s.push(str[i]);
		else{
		if(s.empty() == true) return false;

		else if(match(str[i], s.top()) == false) return false;
		else
			s.pop();
		}
	}
	return (s.empty() == true);	
}

int main(){

	string str = "[{()}]";
	cout << isBalanced(str);
	return 0;
}
