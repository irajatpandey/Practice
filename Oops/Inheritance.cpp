#include<bits/stdc++.h>
using namespace std;
class  Vehicle{
    private:
    int maxSpeed;

    protected: // Protected member are accessible to its child only
    int numTyres;

    public: 
    string color;
};
class Car : public Vehicle{
     public:
        int numGears;
     
        void print(){
            cout << "Number of Tyres " << numTyres << endl;
            cout << "NumGears " <<  numGears << endl;
            cout << "Color "  << color << endl;
        }
};

int main(){

    Vehicle v;
    v.color = "Red";
    
    Car c;
    c.color = "Blue";
    c.numGears  = 5; 
    c.print();


}