#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    string str , str2;
    int cnt = 0;
    cin >> str >> str2;
    vector<pair<char, int>> last;
    vector<char> smallOutput;
    for (int i=0; i<str2.size(); i++) {
        char c = str2[i];
        int n = 0;
        switch(c) {


            case 'w':

                smallOutput.push_back( str[cnt++]);
                last.push_back({'w', 0});
                break;

            case 'd':
                n = 0;
                while(str2[++i] >= '0' && str2[i] <= '9')  n = (n * 10) + (str2[i] - '0');
                
                while(n--) {
                    cnt--;
                    smallOutput.pop_back();
                    
                }
                last.push_back({'d', n});
                break;


            case 'u':
                if (last.back().first == 'w') {
                    smallOutput.pop_back();
                } else {
                    n =  last.back().second;
                    while(n--) {
                        smallOutput.push_back(str[cnt++]);
                    }
                }
        }
    }
    string finalAnswer;
    for (auto c: smallOutput) {
        finalAnswer += c;
    }
    cout << finalAnswer << endl;
}