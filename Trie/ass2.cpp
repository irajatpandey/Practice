#include <iostream>
#include <fstream>
#include<string.h>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class TrieNode{
public:
    TrieNode* data[26];
    TrieNode *prev=NULL;
    int idx;
    bool end=false;
    int frequency = 0;
    TrieNode() {
        frequency = 0;
        for(auto &i : data) {
            i = nullptr;
        }
    }
};
void insert(TrieNode* root, const string& key, int n,unordered_map<int,TrieNode *>m) {
    auto* new_node = new TrieNode;
    for(char i : key) {
        int index = i - 'a';
        if(!root->data[index]) {
            root->data[index] = new_node;
        }
        root->prev=root;
        root->idx=index;
        root = root->data[index];
    }
    m[n]=root;
    root->end=true;
}
void find(TrieNode *root,vector<char> &ans)
{
    if(!root)
    return;
    while(root)
    {
        int temp=root->data[root->idx];
        ans.push_back(temp+'a');
        root=root->prev;
    }
}
int main() {
   unordered_map<int,TrieNode *>m;
    TrieNode *root = new TrieNode;
    ifstream fin;
    fin.open("EnglishDictionary.csv");
    string line;
    while (fin) {
        int number =0;
        string current, freq;
        int i = 0;
        getline(fin,line);
        while(line[i] != ',') {
            current += line[i];
            ++i;
        }
        ++i;
        while(line[i]) {
            freq += line[i];
            ++i;
        }
        insert(root, current, number,m);
        number++;
        line.clear();
    }
    int n;
    cin>>n;
    vector<char>ans;
    find(m[n],ans);
    reverse(ans.begin(),ans.end());
    for(auto it : ans) cout << it;
    return 0;
}