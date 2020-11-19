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


int numberOfNodes(BinaryTree *root){
    if(root == NULL)
      return 0;

      return 1 + numberOfNodes(root -> left) + numberOfNodes(root -> right);
}
int main(){

    // binary tree formation 
    BinaryTree* root = new BinaryTree(4);   /*        4        */
    root->left = new BinaryTree(2);         /*       / \       */
    root->right = new BinaryTree(5);        /*      2   5      */
    root->left->left = new BinaryTree(1);   /*     / \ / \     */
    root->left->right = new BinaryTree(1);  /*    7  1 2  3    */
    root->right->left = new BinaryTree(2);  /*      / /        */
    root->right->right = new BinaryTree(3); /*     6 1         */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);
    
    cout << numberOfNodes(root);



}