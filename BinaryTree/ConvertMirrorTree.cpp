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

void preOrder(BinaryTree *root){

    if(!root)
        return;

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);

}


/* (1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
   (2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
   (3)  swap left and right sub trees
*/
void mirrorTree(BinaryTree* root){
     if(root == nullptr) return;
     swap(root -> left, root -> right);

     mirrorTree(root -> left);
     mirrorTree(root -> right);

    
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

   mirrorTree(root);
   preOrder(root);

   mirrorTree(root);

   cout << endl; 

   preOrder(root);

}