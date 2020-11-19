#include <iostream>
#include<string.h>
using namespace std;
class Student{
    char *name;
    int age;

    public:
    Student(char *name, int age){
       // this -> name = name; /* Shallow Copy */
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
        this -> age = age;
    }
    void display(){
        cout << name << " " << age << endl;
    }

};


int main(){

    char name[] = "abcd";
    Student s1 = Student(name, 21);
    s1.display();

    name[3] = 'e';
    Student s2 = Student(name, 24);
    s2.display();

    s1.display();
}