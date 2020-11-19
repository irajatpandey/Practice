#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i,n) for(int i = 0; i < n; i++)
using namespace std;

int hcf(int x, int y){
    if (x == 0) return y;
    if (y == 0) return x;
  
    if (x == y) return x;
  
    if (x > y) return hcf(x - y, y);

    return hcf(x, y - x);
}
int minimumDivisible(int n){
    int smallOutput = 1;
    for(int i = 1; i <= n; i++){
        smallOutput = (smallOutput * i) / hcf(smallOutput, i);
    }
    return smallOutput;
}
int main() {
   int n = 10;
   cout << minimumDivisible(n);

    return 0;
}