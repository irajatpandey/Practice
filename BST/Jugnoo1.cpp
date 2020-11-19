#include<bits/stdc++.h>
using namespace std;
class BST{
    public:
        pair<int, int> p;
        BST *left,   *right;
        BST(int x, int y){
            left = right = NULL;
            p.first = x;
            p.second = y;
        }

        BST* insert(BST *root, int x, int y){
            if(!root){
                root = new BST(x, y);
                return root;
            } 
            if(root -> p.second > y)
                root -> left = insert(root -> left, x, y);

            else
                root -> right = insert(root -> right, x, y);

            return root;
    
        }   
            
        


};