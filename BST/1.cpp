#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> v1, vector<int> v2){  
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> ans;
    while(i < v1.size() and j < v2.size()){
        if(v1[i] > v2[j]){
            ans.push_back(v2[j++]);
        }
        else
            ans.push_back(v1[i++]);
    }

    while(i <= v1.size() - 1) ans.push_back(v1[i++]);
    while(j <= v2.size() - 1) ans.push_back(v2[j++]);

    return ans;
}
int main(){

    vector<int> v1{1, 3, 5, 7};
    vector<int> v2{2, 4, 6, 8};

    vector<int> a = merge(v1, v2);
    for(int i : a) cout << i << " ";

}