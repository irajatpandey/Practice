/* https://practice.geeksforgeeks.org/problems/number-of-occurrence/0 */
#include<bits/stdc++.h>
using namespace std;

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

    int first = firstOccurrence(arr, 0, n -1, target);    
    int last = lastOccurrence(arr, 0, n - 1, target);

    if(first != -1 and last != -1)
        cout << "Total count of " << target << " is " << last - first + 1;



    delete arr;
}