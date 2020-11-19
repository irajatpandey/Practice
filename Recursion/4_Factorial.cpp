#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n == 0) return 1;
    int smallOutput = n * factorial(n - 1);
    return smallOutput;
}

int main() {
    int n; cin >> n;

    cout << factorial(n);
    return 0;
}