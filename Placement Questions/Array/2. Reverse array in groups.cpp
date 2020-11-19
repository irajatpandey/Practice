#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i,n) for(int i = 0; i < n; i++)
using namespace std;

vector<int> reverseInGroups(vector<int> &v, int n, int k){
    loop(i, n){
    if(k >= n){
        reverse(all(v));
    }
    else{
        int left = i;
        int right = min(i + k - 1, n - 1);
        while(left <= right){
            swap(v[left++], v[right--]);
        }
    }
    }
    return v;

}
int main() {
    int n; cin >> n;
    int k; cin >> k;

    vector<int> v(n);
    loop(i, n) cin >> v[i];

    vector<int> ans = reverseInGroups(v, n, k);
    loop(i, n) cout << ans[i] << " ";

    return 0;
}