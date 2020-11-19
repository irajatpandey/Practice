#include<bits/stdc++.h>
using namespace std;

class Student{
    int rollno;
    public:
       /*  Student(){
            cout << "Student default constructor is called " << endl;
        } */
        void print(){
            cout << "Hehehe\n";
        }
        Student(int x){
            rollno = x;
            cout << "Parametrized constructor " << rollno << endl;
        }

};

class Academics : virtual public Student{
       public:
      int subMarks;
      Academics():Student(14){
          cout << "Academic default constructor \n"; 
      }
};
class Sports : virtual public Student{
     public:
     int score;
        Sports(){
            cout << "Sports default constructors \n";
        }
};

class Result : public Academics, public Sports{
      public:
      int total;
     Result() : Student(111){
        cout << "Result constructor " << endl;
     }
};
int main() {
    Result r;
    
    r.print();

    return 0;
}