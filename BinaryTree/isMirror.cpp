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




// Time complexity O(n);
// Space Complexity O(n);
bool isMirrorTree(BinaryTree* root1, BinaryTree *root2){
    if(root1  == NULL and root2  == NULL)
        return true;
    if(root1  == NULL or root2  == NULL)    
        return false;

    return (root1 -> data == root2 -> data) and isMirrorTree(root1 -> left, root2 -> right) and isMirrorTree(root1 -> right, root2 -> left);
    
}

int main(){

    BinaryTree *root1   = new  BinaryTree(1); 
    root1 ->left = new  BinaryTree(2); 
    root1 ->right = new  BinaryTree(3); 
    root1 ->left -> left = new  BinaryTree(4); 
    root1 ->right -> left = new  BinaryTree(5); 
    root1 ->right -> right = new  BinaryTree(8); 
    root1 ->right -> left -> left = new  BinaryTree(6); 
    root1 ->right -> left -> right = new  BinaryTree(7); 
    root1 ->right -> right -> left = new  BinaryTree(9); 
    root1 ->right -> right -> right = new  BinaryTree(10); 


    
    BinaryTree *root2   = new  BinaryTree(1); 
    root2 ->left = new  BinaryTree(2); 
    root2 ->right = new  BinaryTree(3); 
    root2 ->left -> left = new  BinaryTree(4); 
    root2 ->right -> left = new  BinaryTree(5); 
    root2 ->right -> right = new  BinaryTree(8); 
    root2 ->right -> left -> left = new  BinaryTree(6); 
    root2 ->right -> left -> right = new  BinaryTree(7); 
    root2 ->right -> right -> left = new  BinaryTree(9); 
    root2 ->right -> right -> right = new  BinaryTree(10); 

   cout << isMirrorTree(root1, root2);
   
  

  

}