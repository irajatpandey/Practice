#include<bits/stdc++.h>
#include<string>
using namespace std;
/* void swap(string &a, int i, int j) {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    } */
void reverse(string &a, int start) {
        int i = start, j = a.size() - 1;
        while (i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
int nextGreaterElement(int n){
    string a = to_string(n);
    int i = a.size() - 2;
     while (i >= 0 && a[i + 1] <= a[i]) i--;
        

     if (i < 0)
            return -1;
        int j = a.length() - 1;
        while (j >= 0 && a[j] <= a[i]) {
            j--;
        }
        swap(a[i], a[j]);
        reverse(a, i + 1);   
         try {
            int ans = std :: stoi(a);
            return ans;
        } catch (exception e) {
            return -1;
        }

}
int main(){

    int n; cin >> n;
    cout << nextGreaterElement(n) << endl;

}
