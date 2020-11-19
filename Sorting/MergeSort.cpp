#include<bits/stdc++.h>
using namespace std;
void merge(int *arr, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1];
    int right[n2];

    for(int i = 0; i < n1; i++){
        left[i] = arr[start + i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = start;
    while(i < n1 and j < n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else
            arr[k++] = right[j++];
    }
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];

}
void mergeSort(int *arr, int start, int end){
    if(start < end){
        int mid = (start + end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
    cout << arr[i] << " ";

    return 0;
}