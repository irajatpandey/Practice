#include <iostream>
#include<string.h>
using namespace std;
class Student{
    public:
    char *name;
    int age;

    
    Student(char *name, int age){
       // this -> name = name; /* Shallow Copy */
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
        this -> age = age;
    }

    Student(Student const &s){
        this -> name = new char[strlen(s.name) + 1];
        strcpy(this -> name, s.name);
        this -> age = s.age;
    }
    void display(){
        cout << name << " " << age << endl;
    }

};


int main(){

    char name[] = "abcd";
    Student s1 = Student(name, 21);
    s1.display();

    Student s2(s1);
    s2.name[0] ='x';
    s1.display();
    s2.display();
   
}