#include<bits/stdc++.h>
using namespace std;
/* Recursive Approach */
int firstOccurrence(int *arr, int start, int end, int target ){
    int ans = -1;
   while(start <= end){
       int mid = start + (end - start)/2;
       if(arr[mid] == target){
           ans = mid;
           end = mid -1; 
       }
       else if(arr[mid] > target) end = mid - 1;
       else start = mid + 1;
   }
   return ans;
}
int lastOccurrence(int *arr, int start, int end , int target){
    int ans = -1;
       while(start <= end){
       int mid = start + (end - start)/2;
       if(arr[mid] == target){
           ans = mid;
           start = mid + 1; 
       }
       else if(arr[mid] > target) end = mid - 1;
       else start = mid + 1;
   }
   return ans;
}
 /*     10
        1 3 5 7 10 10 10 12 13 15 
    */
int main(){

    cout << "Enter the size of an array " << endl;
    int n; cin >> n;
    int *arr = new int[n];
   
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the element which you are looking for " << endl;
    int target; cin >> target;

    int index = firstOccurrence(arr, 0, n -1, target);
    if(index == -1) cout << "Not Found\n";
    else cout << "First occurrence of " << target << " is " << index << endl;
    
    int last = lastOccurrence(arr, 0, n - 1, target);
    if(last == -1)  cout << "Not Found\n";
    else cout << "Last occurrence of " << target << " is " << last << endl;


    delete arr;
}