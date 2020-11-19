#include<bits/stdc++.h>
using namespace std;
class Registration{
	public:
		int roll;
		

		Registration(int x){
			roll = x;
		}

		static int generateReg;
		static int getReg(){
			 generateReg += 10;
			 return generateReg;
		}
};


int Registration :: generateReg = 12345;
int main(){

	Registration reg(10);
	cout << reg.getReg() << endl;

	Registration r1(20);
	cout << reg.getReg() << endl;
	



}