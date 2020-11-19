#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s){
    int i = 0, len = 0, start = 0, end;
        // remove leading spaces
        while(i < s.size() and s[i] == ' ') i++;
     
        start = i;
        // remove trailing spaces
        i = s.size() - 1;
        while(i >= 0 and s[i] == ' ') i--; 
        end = i;

        // remove multiple spaces btw. words
        for (i = start, len = 0; i <= end; i++) {
            if (' ' == s[i] && ' ' == s[i - 1])
                continue;
            s[len++] = s[i];
        }
        
        s.erase(s.begin() + len, s.end());

        reverse(s.begin(), s.end());
        for (i = 0, start = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        // last word
        reverse(s.begin() + start, s.end());
        return s;
    }
    

int main(){

    string str; getline(cin, str);
    cout << reverseWords(str) << endl;

    return 0;
}