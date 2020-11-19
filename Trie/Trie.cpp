#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode **children;
        bool isTerminal;
        int frequency;
        TrieNode(char data){
            this -> data = data;
            isTerminal = false;
            children = new TrieNode*[26]; 
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
        }



};
class Trie{
    TrieNode *root;
    public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word){
        if(word.size() == 0) {
            root -> isTerminal = true;
            retrun;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root -> children[index] = child;

        }
        insertWord(child, word.substr(1));
    }
    void insertWord(string word){
        insertWord(root, word);
    } 
     bool searchWord(TrieNode*root,string word){
        ///base case
        if(word.length()==0)
        {
            if(root -> isTerminal == true)
             return true;
            else 
                return false;
        }
        /// small calculation
        char firstCharacter = word[0];
        TrieNode *child;
        int index = firstCharacter-'a';
        child = root -> children[index];
        if(child == NULL)
        {
            return false;

        }
        else{
            ///recursive call
            return searchWord(child,word.substr(1));
        }
    }

    bool searchWord(string word){
        return searchWord(root, word);
    }

};
int main(){

    Trie root;
    root.insertWord("abc");
    root.insertWord("cde");
    root.insertWord("hel");

    if(root.searchWord("hll"))
        cout << "YES\n";
        else cout << "NO\n";

}