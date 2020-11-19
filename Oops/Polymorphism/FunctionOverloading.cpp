#include<iostream>
using namespace std;
class shape{
    public:
float area(int r){
    return (3.14 * r * r);
}
int area(int x, int y){
    return x * y;
}
};

int main(){
    shape s;
    cout << s.area(1) << endl;
    cout << s.area(10, 20);
}