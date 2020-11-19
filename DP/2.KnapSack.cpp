#include<bits/stdc++.h>
using namespace std;
int knapSack(int *weight, int *price, int capacity, int n){
    if(capacity == 0 or n == 0) return 0;

    if(capacity >= weight[n - 1]){
        return max(price[n - 1] + knapSack(weight, price, capacity - weight[n - 1], n - 1), knapSack(weight, price, capacity, n - 1));
    }
    else 
        return knapSack(weight, price, capacity, n - 1);
    
}
int **dp = nullptr;
void setMatrix(int n, int w){
    dp = new int*[w];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[w];
    }

   for(int i = 0; i < n; i++) 
    memset(dp[i], -1, w *sizeof(dp[i]));

}
int knapSack_Memoization(int *weight, int *price, int capacity, int n, int **dp){
    if(capacity == 0 or n == 0) return 0;

    if(dp[n][capacity] != -1)
        return dp[n][capacity];

    if(capacity >= weight[n - 1]){
        return dp[n][capacity] = max(price[n - 1] + knapSack_Memoization(weight, price, capacity - weight[n - 1], n - 1, dp), knapSack_Memoization(weight, price, capacity, n - 1, dp));
    }
    else 
        return dp[n][capacity] = knapSack_Memoization(weight, price, capacity, n - 1, dp);

}
int knapSack_topdown(int *weight, int *price, int capacity, int n){
    int dp[n+1][capacity+1] ={0};
    memset (dp[0], 0, sizeof dp[0]);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            if(j >= weight[i - 1]){
                dp[i][j] = max(price[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
                //cout << dp[i][j] << " ";
            }
            else
                dp[i][j] = dp[i -1][j];
        }
        //cout << endl;

    }
        return dp[n][capacity];

}
int main(){ 
    /* Input:
    price = [ 20, 5, 10, 40, 15, 25 ]
    weight = [ 1, 2, 3, 8, 7, 4 ]
    capacity = 10
    
    Output: Knapsack value is 60 */

    int price[] = { 20, 5, 10, 40, 15, 25 };; 
    int weight[] =  {  1, 2,  3,  8,  7, 4 }; 
    int capacity = 10; 
    int n = sizeof(price) / sizeof(price[0]); 

    cout << knapSack(weight, price, capacity, n) << endl;
    setMatrix(n+1, capacity + 1);
    
    cout << knapSack_Memoization(weight, price, capacity, n, dp) << endl;

    cout << knapSack_topdown(weight, price, capacity, n) << endl;
 
    return 0;
}