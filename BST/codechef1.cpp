#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i,n) for(int i = 0; i < n; i++)

using namespace std;

int minimumTime(vll v, ll n){
   sort(all(v), greater<int>());
   vector<int> burner(2, 0);
   if(n == 1) return v[0];
   burner.pb(v[0]);
   burner.pb(v[1]);
   ll ans = 0;
   int k = 0;
   for(int i = 2; i < n ; i++){
       ans += max(burner[i - k], burner[i + 1 - k]);
       k++;
       if(burner[i - k] < burner[i + 1 - k]){
           burner[i - k] += v[i];
       }
       else{
           burner[i + 1 - k] += v[i];
       }
   }
   return ans;
}
int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    ll n; cin >> n;
	    vector<ll> v(n);
	    loop(i, n) cin >> v[i];
	    
	    cout << minimumTime(v, n) << endl;
	    
	}
	
	return 0;
}
