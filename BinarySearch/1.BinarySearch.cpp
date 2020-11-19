#include<bits/stdc++.h>
using namespace std;
/* Iterative Approach */
int binarySearch(int *arr, int s, int e, int target){
    while(s <= e){
        int m = s + (e - s)/2;
        if(arr[m] == target) return m;
        else if(arr[m] > target){
            e = m - 1;
        }
        else{
            s = m + 1;
        }
    }
    return -1;
}
/* Recursive Approach */
int binarySearch_recursive(int *arr, int s, int e, int target ){
    if(s <= e){
        int m = s + (e - s)/2;
        if(arr[m] == target) return m;
        if(arr[m] > target) return binarySearch_recursive(arr, s, m - 1, target);
        else return binarySearch_recursive(arr, m + 1, e, target);
    }
    return -1;
}
int main(){

    cout << "Enter the size of an array " << endl;
    int n; cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the element which you are looking for " << endl;
    int target; cin >> target;

    if(binarySearch_recursive(arr, 0, n - 1, target) == -1){
        cout << "Element not fount " << endl;
    }
    else{
        cout << "Element found at index " << binarySearch_recursive(arr, 0, n - 1, target) << endl;
    }
    delete arr;
}