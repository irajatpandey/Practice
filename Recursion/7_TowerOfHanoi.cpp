#include<iostream>
using namespace std;

void toh(int n, int t1id, int t2id, int t3id){
    // write your code here
    if(n == 0) return;
    toh(n - 1, t1id, t3id, t2id);
    cout << n << "[" << t1id << " -> " << t2id << "]" << endl;
    toh(n - 1, t3id, t2id, t1id);
    
  }

//1[10 -> 11]


int  main() {

    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
  }