#include<bits/stdc++.h>
using namespace std;
class Complex{
    public:
    int real, img;
    
    Complex(int r = 0, int i = 0){
        real = r;
        img =  i;
    }
    Complex operator +(Complex const &c1) const{
        Complex c3;
        c3.real = this -> real + c1.real;
        c3.img =  this -> img +  c1.img;
        return c3;
    } 
    void display(){
        cout << real << "+ i " << img << endl;
    }
};


int main() {
    Complex c1(10, 20);
    Complex c2(10, 20);
    Complex c3 = c1 + c2;
    c1.display();
    c2.display();
    c3.display();

    return 0;
}