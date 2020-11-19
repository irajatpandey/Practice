#include<bits/stdc++.h>
using namespace std;
class B{
public:
	void print();
};
void test();
class A{
	int x;
	protected: 
		int y;
	public :
	int z;

	friend void B :: print();
	friend void test();	
};
/*

	Friend Function are not the member function of the class
	Friend Function do not have this pointer because they are not the member of the class

*/

void B :: print(){
	A a;
	a.x = 100;
	a.y = 200;
	cout << a.x << " " << a.y << endl;  

}
void test(){
	A o;
	o.x = 10;
	o.y = 20;
	cout << o.x << " " << o.y << endl;  
}
int main(){

	test();
	B b;
	b.print();

 return 0;
}