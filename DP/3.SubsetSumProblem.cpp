#include<bits/stdc++.h>
using namespace std;

/* Time complexity of the above code is Exponential  and we can reduce it with th help of the DP*/
bool subsetSum_bruteForce(int *arr, int n, int sum){
    if(sum == 0) return true;
    if(n == 0) return false;
    if(arr[n - 1] <= sum){
        return (subsetSum_bruteForce(arr, n - 1, sum - arr[n - 1]) or subsetSum_bruteForce(arr, n - 1, sum));
    }
    else
        return subsetSum_bruteForce(arr, n - 1, sum);
}

int subsetSum(int *arr, int n, int sum){
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

     return dp[n][sum];
    
}
int main(){

    int arr[] = {2, 3, 7, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 11;
    //cout << subsetSum_bruteForce(arr, size, sum);
    if(subsetSum(arr, size, sum))
        cout << "Subset is present" << endl;
    else
        cout << "Subset is not present" << endl;
    return 0;
}