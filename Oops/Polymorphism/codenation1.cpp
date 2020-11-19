#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll in = v[0];
    ll ex = 0;
    ll ex_ans = 0;
    for(int i = 1; i < n; i++){
	    ex_ans = (in > ex)? in: ex; 
        in = ex + v[i]; 
        ex = ex_ans; 
    }

    cout <<  ((in > ex)? in : ex) << endl; 
    return 0;
}