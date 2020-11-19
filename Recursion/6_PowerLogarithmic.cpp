#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    // write your code here
    if(n == 0) return 1;
    int smallOutput = powerLogarithmic(x, n/2);
    int finalAnswer = smallOutput * smallOutput;
    
    if(n % 2 != 0) finalAnswer = finalAnswer * x;
    return finalAnswer;
    
}

int main(){
    int x,n; cin>>x>>n;
    cout << powerLogarithmic(x,n);
}