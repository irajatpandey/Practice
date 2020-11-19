#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(int *arr, int n){
	stack<int> s;
	vector<int> output;

	for(int i = n - 1; i >= 0; i--){	
		if(s.size() == 0)
			output.push_back(-1);
		

		if(s.size() > 0 and s.top() > arr[i]) 
			output.push_back(s.top());

		else if(s.size() > 0 and s.top() <= arr[i]){
			while(s.size() > 0 and s.top() <= arr[i]) s.pop();

			if(s.size() == 0) output.push_back(-1);
			else output.push_back(s.top());
		}
		
		s.push(arr[i]);


	}
	return output;
}
int main(){

	int arr[] = {1, 3, 0, 0, 1, 2, 4};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> output = nextGreaterElement(arr, n);
	
	reverse(output.begin(), output.end());
 	cout << "Output vector : ";
	for(auto it : output) cout << it << " ";

	return 0;
}