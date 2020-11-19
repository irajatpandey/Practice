#include<bits/stdc++.h>
using namespace std;
int fibo1(int n){
    if(n == 0 or n == 1) return 1;
    return fibo1(n - 1) + fibo1(n - 2);
}

int fibo2(int n, vector<int> &dp){
    if(n == 0 or n == 1) return 1;
    if(dp[n] > 0) return dp[n];
    int output = fibo2(n - 1, dp) + fibo2(n - 2, dp);
    dp[n] = output;
    return output;
}



int main(){

    vector<int> dp(21, 0);
    cout << fibo2(20, dp) << endl;
    cout << fibo1(20) << endl;

    return 0;
}