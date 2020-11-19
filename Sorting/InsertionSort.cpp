#include<bits/stdc++.h>
using namespace std;
void insertionSort(int *arr, int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int temp = arr[i];

        while(j >= 0 and arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
void printArray(int *arr, int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){

    int arr[] = {5, 4, 10, 1, 6, -2}; // temp = 4
    int n = 6;

    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}