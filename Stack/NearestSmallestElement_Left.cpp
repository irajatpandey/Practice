#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(int *arr, int n){
	vector<int> ans;
	stack<int> s;
	
	for(int i = 0; i < n; i++){
		if(s.empty()) 
			ans.push_back(-1);
		else if(s.size() > 0 and s.top() < arr[i])
			ans.push_back(s.top());
		else{
			while(s.size() > 0 and s.top() >= arr[i]){
				s.pop();
			}

			if(s.empty())
				ans.push_back(-1);
			else
				ans.push_back(s.top());
		}
		s.push(arr[i]);

	}
	return ans;
}
int main(){
	int arr[] = {4, 5, 2, 10, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> output = nextSmallerElement(arr, n);
	for(int i = 0; i < n; i++)
		cout << output[i] << " ";

	return 0;
}