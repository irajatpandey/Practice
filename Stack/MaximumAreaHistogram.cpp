#include<bits/stdc++.h>
using namespace std;
int maximumArea(int *arr, int n){
	vector<int> NSL;
	vector<int> NSR;
	vector<int> ans(n);
	stack<pair<int, int>> s1;
	stack<pair<int, int>> s2;

	for(int i = 0; i < n; i++){
		if(s1.empty()) NSL.push_back(-1);
		else if(s1.size() > 0 and s1.top().first < arr[i]){
			NSL.push_back(s1.top().second);
		}
		else {
			while(s1.size() > 0 and s1.top().first >= arr[i]) s1.pop();
			if(s1.empty()) NSL.push_back(-1);
			else 
				NSL.push_back(s1.top().second);
		}

		s1.push({arr[i], i});
	}


	for(int i = n - 1; i >= 0; i--){
		if(s2.empty()) NSR.push_back(n);

		else if(s2.size() > 0 and s2.top().first < arr[i]){
			NSR.push_back(s2.top().second);
		}
		else{
			while(s2.size() > 0 and s2.top().first >= arr[i]) s2.pop();
			if(s2.empty())
				NSR.push_back(n);
			else
				NSR.push_back(s2.top().second);
		}
		s2.push({arr[i], i});

	}
		reverse(NSR.begin(), NSR.end());

	for(int i = 0; i < n; i++)
		ans[i] = arr[i] * (NSR[i] - NSL[i] - 1);
	

	return *max_element(ans.begin(), ans.end());
}
int main(){
 
 int arr[] = {6, 2, 5, 4, 5, 1, 6};
 int n = sizeof(arr)/sizeof(arr[0]);

 int ans = maximumArea(arr, n);
 
 	cout << ans << " ";

  return 0;
}