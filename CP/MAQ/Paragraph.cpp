#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int             long long
#define pb              push_back
#define vi              vector<int>
#define all(v)          v.begin(), v.end()
#define loop(i,n)       for(int i = 0; i < n; i++)
#define w(x)            int x; cin>>x; while(x--)
#define mii             map<int,int>
#define pii             pair<int,int>
#define mp              make_pair
#define pqb             priority_queue<int> // max heap
#define pqs             priority_queue<int,vi,greater<int> >// min heap
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007

void c_p_c() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

bool comp(pair<string, int> &p1, pair<string, int> &p2){
    if(p1.second == p2.second) return p1.second < p2.second;
    return p1.second > p2.second;   
}
int32_t main() {
   
 
    string s; getline(cin, s);
    unordered_map<string, int> count_occurennce;

    
    string temp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            temp += s[i];
        }
        else{
            count_occurennce[temp]++;
            temp.erase();
            continue;
        }
    }
    count_occurennce[temp]++;
    vector<pair<string, int>> v;
    

    for(auto it : count_occurennce){
 
       v.pb({it.first, it.second}); 
    } 


  

    sort(all(v), comp);



    for(auto it : v) cout << it.first << " " << it.second << endl;
    return 0;
}