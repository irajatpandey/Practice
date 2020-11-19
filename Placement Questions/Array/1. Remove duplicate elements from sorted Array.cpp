#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i,n) for(int i = 0; i < n; i++)
using namespace std;

int remove_duplicate(int arr[],int n){
    int k = 0;
    for(int i = 1; i < n; i++){
        if(arr[i - 1] != arr[i]){
            arr[k++] = arr[i - 1];
        }
    }
    if(arr[k-1] != arr[n-1]){
        arr[k++] = arr[n - 1];
       
    }
    return k;

}
int main() {
    int n; cin >> n;

    int arr[n];
    loop(i, n) cin >> arr[i];
    int k = remove_duplicate(arr, n);
    loop(i, k) cout << arr[i] << " ";
    return 0;
}