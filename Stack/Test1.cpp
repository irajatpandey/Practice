#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		long n; cin >> n;
		string str;
		cin >> str;
		int l = 0;
		int r = 0;
		int cnt = 0;
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(str[i] == 'L') l++;
			else if(str[i] == 'R') r++;
			else cnt++;
		}

		if(l > r ) ans = l - r + cnt;
		else if(r >= l) ans = r - l + cnt;

		cout << ans << endl;
	}
}