#include <iostream>
using namespace std;

class Mango{
    public:
    int price;
    int weight;
    char color[10];
};

int main(){

    Mango m1; //Creating Objects Statically 
    Mango *m2 = new Mango; // Creating Object Dynamically

    m1.price = 60;
    m1.weight = 1;
    m1.color = "red";

    cout << m1.color;

    return 0;
}