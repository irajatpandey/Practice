#include <bits/stdc++.h>
using namespace std;
class BinaryTree{
    public:
    int data;
    BinaryTree  *left, *right;

    BinaryTree(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
    
};


/* The problem can also be solved using simple recursive traversal. We can keep track of the level of a node by passing a parameter to all recursive calls. 
   The idea is to keep track of the maximum level also. Whenever we see a node whose level is more than maximum level so far, 
   we print the node because this is the first node in its level (Note that we traverse the left subtree before right subtree). */

   


// Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).
// Auxiliary Space: O(n), due to the stack space during recursive call.


void leftView(BinaryTree *root){
    
}

int main(){

    BinaryTree *root   = new  BinaryTree(1); 
    root ->left = new  BinaryTree(2); 
    root ->right = new  BinaryTree(3); 
    root ->left -> left = new  BinaryTree(4); 
    root ->right -> left = new  BinaryTree(5); 
    root ->right -> right = new  BinaryTree(8); 
    root ->right -> left -> left = new  BinaryTree(6); 
    root ->right -> left -> right = new  BinaryTree(7); 
    root ->right -> right -> left = new  BinaryTree(9); 
    root ->right -> right -> right = new  BinaryTree(10); 

   leftView(root);

}