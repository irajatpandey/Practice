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


void printLeaves(BinaryTree *root){
    if(root == NULL) return;
    if(root -> left == NULL and root -> right == NULL) 
        cout << root -> data << " ";
    printLeaves(root -> left);
    printLeaves(root -> right);
}
int main(){

    // binary tree formation 
    BinaryTree* root = new BinaryTree(4);   /*        4        */
    root->left = new BinaryTree(2);         /*       / \       */
    root->right = new BinaryTree(5);        /*      2   5      */
    root->left->left = new BinaryTree(1);   /*     / \ / \     */
    root->left->right = new BinaryTree(1);  /*    1  1 2  3    */
    root->right->left = new BinaryTree(2);  /*      / /        */
    root->right->right = new BinaryTree(3); /*     6 1         */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);
    
    printLeaves(root);



}