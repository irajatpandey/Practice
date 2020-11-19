#include<bits/stdc++.h>
//types
using namespace std;
void solve(vector<int> &v){
    int cs,ce,fs,fe; //current start and end, final start and end
    cs=ce=fs=fe=0; //setting all to intial value
    int ans=INT_MIN; //final answer setting to INT_MIN, so it will be updated at least once
    int sum=0; // sum of currently selected subarray

  unordered_set<int> um; // can unordered set for hashing
  
    while(ce<v.size()){  //while current end is with in the size of array
       
      if(um.find(v[ce])!=um.end()){ //if found in hash, i.e. present in currrently selected subarray 
            while(v[cs-1]!=v[ce]) { // start from current_start until that element is found
                sum -= v[cs];  //continue to remove, so current sum will be changed
                um.erase(v[cs]); //remove from hash
                cs++; 
            }
      } 
        //include number
        sum+=v[ce];  // take this element and add to currently selected subarray
        um.insert(v[ce]); // insert in to hash 
      if(sum>ans){ //update final answer if required
            fs=cs;
            fe=ce;
            ans=sum;
        }
        ce++;
    }

  //printing out the answer
    cout<<"subarray is "<<endl;
    for(int i=fs;i<=fe;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<"max_sum:"<<ans<<endl;
    cout<<"-----------------"<<endl;
}
int main()
{
    int n; //number of element in array
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
       cin>>v[i];
    }
    solve(v);
    return 0;
}