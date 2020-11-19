#include<bits/stdc++.h>
using namespace std;
/* Recursive Approach */
int binarySearch_recursive(int *arr, int s, int e, int target ){
    if(s > e) return -1;
        int m = s + ((e - s)/2);
        
        if(arr[m] == target) return m;
        else if(arr[m] > target) return binarySearch_recursive(arr, m + 1, e, target);
        else  
            return binarySearch_recursive(arr, s, m - 1, target);
    
    //return -1;
}
int main(){

    cout << "Enter the size of an array " << endl;
    int n; cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the element which you are looking for " << endl;
    int target; cin >> target;

    int index = binarySearch_recursive(arr, 0, n -1, target);
    if(index == -1) cout << "Element not found " << endl;
    else cout << "Element found at index " << index << endl;

    delete arr;
}