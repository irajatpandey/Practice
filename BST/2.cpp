#include<bits/stdc++.h>
using namespace std;
void remove(string str, vector<string> &v){
    string word = ""; 
   for (auto x : str) 
   { 
       if (x == ' ') 
       { 
           v.push_back(word);
           word = ""; 
       } 
       else
       { 
           word = word + x; 
       } 
   }  
   v.push_back(word);
}
void removeDupWord(string str, map<string, string> &map, vector<string> v) 
{ 
 
  for(auto it : v){
      if(map.find(it) == map.end())
        map[it] = it;
      else
        continue;  
  }
} 
 
int main(){

    string s;
    getline(cin,s); 
     map<string,string> map;
       vector<string> v;
    remove(s, v);
     removeDupWord(s, map, v);
       
     for(auto it : v){
       
         cout << map[it] << " ";
     }

}