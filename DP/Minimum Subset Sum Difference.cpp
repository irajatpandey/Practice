#include<bits/stdc++.h>
using namespace std;


int subsetSum(int *arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    bool dp[n + 1][sum + 1];
     for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(i == 0 ) dp[i][j] = false;
            if(j == 0)  dp[i][j] = true;
        }
     }

     for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i - 1] <= j){
                dp[i][j] = (dp[i -1][j- arr[i - 1]] || dp[i - 1][j]); 
            }
            else
                dp[i][j] = dp[i - 1][j];
            
        }

     }

     vector<int> v;
     for(int i = 0; i <= sum/2; i++){
        if(dp[n][i])
        v.push_back(i);
     }
     int ans = 2e5;
     for(int i = 0; i <v.size(); i++){
        ans = min(ans, (sum - 2*v[i]));
     }

     return ans;


    
}
int main(){

    int arr[] = {36, 7, 46, 40};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 11;
    //cout << subsetSum_bruteForce(arr, size, sum);
    cout << subsetSum(arr, size) << endl;
    return 0;
}