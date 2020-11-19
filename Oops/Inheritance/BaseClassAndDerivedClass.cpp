#include<bits/stdc++.h>
using namespace std;

class A{
    public:
   void fun1(){
        cout << "Base class\n";
    }

};

class B : public A{
    public :
    void fun2(){
        cout << "Base class\n";
    }

};


int main(){
    B b;
    A obj = b;
    
    return 0;
}