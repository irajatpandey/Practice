#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    A(){
        cout << "This is A's Constructor " << endl;
    }
    ~A(){
        cout << "This is A's destructor " << endl;

    }

};


class B : public A{
    public:
    B(){
        cout << "This is B's Constructor " << endl;
    }
    ~B(){
        cout << "This is B's destructor " << endl;

    }

};

class C : public B{
    public:
     C(){
        cout << "This is C's Constructor " << endl;
    }

    ~C(){
        cout << "This is C's destructor " << endl;

    }

};

int main(){
    C obj;


    return 0;

}