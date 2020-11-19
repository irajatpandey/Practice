
#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
int main()
{
   
    ll testCase; cin >> testCase; 
    while(testCase--)
    {
        ll n; cin >> n;
        ll cnt = 0;
        vector<ll> v(n);
        map<ll,ll> map;
        for(ll i = 0; i < n; i++){
            cin >> v[i];
            map[v[i]]++;
            if(map[v[i]] == 1 && v[i] != 0) cnt++;
        }
        cout << cnt << endl;
    }
    
    return 0;  
}