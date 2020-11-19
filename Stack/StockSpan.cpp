#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpanProblem(int *arr, int n){
	stack<pair<int,int>> s;
	vector<int> output;


	for(int i = 0; i < n; i++){
		if(s.empty()){
			output.push_back(-1);
		}

		else if(s.size() > 0 and s.top().first > arr[i])
			output.push_back(s.top().second);

		else{
			while(s.size() > 0 and s.top().first <= arr[i]) s.pop();
			if(s.empty()) output.push_back(-1);
			else output.push_back(s.top().second);
		}

		s.push({arr[i], i});
	}

	for(int i = 0; i < n; i++)
		output[i] = i - output[i];
	
	return output;
}
int main(){
  int arr[] = {100, 80, 60, 70, 60, 75, 85};
  int n = sizeof(arr)/sizeof(arr[0]);

  vector<int> ans = stockSpanProblem(arr, n);

  for(auto it : ans) cout << it << " ";

  return 0;
}