#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr, int s, int n){
     if(s == n) return ;
     cout << arr[s] << " ";
     printArray(arr, s + 1, n);
}
int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    printArray(arr, 0, n);

    return 0;
}