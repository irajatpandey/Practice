#include<iostream>
using namespace std;
int findPivot(int *arr, int start, int end){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] > arr[mid+1])   return mid + 1;
        if(arr[start] <= arr[end]) start = mid + 1;
        else end = mid - 1;

    }
    return -1;
}
int binarySearch(int *arr, int start, int end, int target){
    int index = findPivot(arr, start, end);
    if(index == -1) return -1;
    else{
        if(target > arr[end]){
           end = index;
           index = 0;
        }
        
        while(index <= end){
            int mid = index + (end - index)/2;

            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) end = mid - 1;
            else index = mid + 1;
        }
    }
    return -1;
}
int main(){
    cout << "Enter the size of an array " << endl;
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the target " << endl;
    int target; cin >> target;
    cout << binarySearch(arr, 0, n - 1, target);
    return 0;

}