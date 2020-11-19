#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define loop(i,n) for(int i = 0; i < n; i++)
using namespace std;


int main() {
    int a, b, c; cin >> a >> b >> c;
    vi v;
    v.pb(a); v.pb(b); v.pb(c);
    sort(all(v));
    cout << v.at(1) << endl;







    
    // int one = a - b;
    // int two = b - c;
    // int three = a - c;

    // if(one * two > 0) cout << b << endl;
    // else if(one * three > 0) cout << c << endl;
    // else cout << a << endl;



    return 0;
}