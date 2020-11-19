#include<iostream>
using namespace std;
class A{
    public: 
    void fun(){
        cout << "This is Base class function\n";
    }
};

class B : public A{
    public:
    void fun(){
        cout << "This is Child class function\n";

    }
};

int main(){
    
    B o;
    A *obj = &o;
    obj -> fun();
}