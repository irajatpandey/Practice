#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int *arr, int n){
     // Number of pass = n - 1
     // Number of comparison = n - 1 - i
    bool flag = false;
     for(int i = 0; i < n - 1; i++){
         flag = false;
         for(int j = 0; j < n - 1 - i; j++){
             if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
             }
         }
         if(flag == false)
            break;
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

    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}