#include<bits/stdc++.h>
using namespace std;
void selectionSort(int *arr, int n){
     // Number of pass = n - 1

     for(int i = 0; i < n - 1; i++){
         int minimumIndex = i;
         for(int j = i + 1; j < n; j++){
             if(arr[j] < arr[minimumIndex]){
                 minimumIndex = j;
             }
         }
         if(minimumIndex != i)
            swap(arr[i], arr[minimumIndex]);
     }
}
void printArray(int *arr, int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){

    int arr[] = {5, 4, 10, 1, 6, -2};
    int n = 6;

    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}