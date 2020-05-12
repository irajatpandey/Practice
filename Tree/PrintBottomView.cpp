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

  // Recursive function to do a pre-order traversal of the tree and fill the map
 // Here node has 'dist' horizontal distance from the root of the
// tree and level represent level of the node


void bottomView(BinaryTree *root){
   

     // create an empty map where
    // key -> relative horizontal distance of the node from root node and
   // value -> pair containing node's value and its level

   
 
}


int main(){


       /*
                               1
                             /   \
                            2     3
                           /     /  \
                          4     5    8
                               / \   /\
                              6   7 9  10

            */
   
   

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

    bottomView(root);

}
