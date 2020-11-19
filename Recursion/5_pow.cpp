#include<bits/stdc++.h>
using namespace std;
int pow(int x, int n){
    if(n == 0){
        return 1;
    }
    int smallOutput = x * pow(x, n - 1);
    return smallOutput;
}

int main() {
    int x, n; cin >> x >> n;

    cout << pow(x, n);
    return 0;
}