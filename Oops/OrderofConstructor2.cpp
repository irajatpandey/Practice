#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int temp;
    A(int x){
        temp = x;
        cout << temp << endl;
        cout << "This is A's Parametrized Constructor " << endl;
    }
    ~A(){
        cout << "This is A's destructor " << endl;

    }

};


class B : public A{
    protected:
    int val;
    public:
    B(int x, int y) : A(x){
        val = y;
        cout << val << endl;
        cout << "This is B's Parametrized Constructor " << endl;
    }
    ~B(){
        cout << "This is B's destructor " << endl;

    }

};

class C : public B{
    public:
    C(int x, int y) : B(x,y) {
        
        cout << "This is C's Constructor " << endl;
    }

    ~C(){
        cout << "This is C's destructor " << endl;

    }

};

int main(){
    C obj(10,20);


    return 0;

}