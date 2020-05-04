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


void identicalTrees(BinaryTree *root1, BinaryTree *root2){
  
}
int main(){

    BinaryTree* root1 = new BinaryTree(4);     /*        4        */
    root1 -> left = new BinaryTree(2);         /*       / \       */
    root1 -> right = new BinaryTree(5);        /*      2   5      */
    root1 -> left -> left = new BinaryTree(1); /*     / \ / \     */
    root1 -> left -> right = new BinaryTree(1);/*    1  1 2  3    */
    root1 -> right -> left = new BinaryTree(2);/*      / /        */
    root1 -> right -> right = new BinaryTree(3); /*   6  1        */
    root1 -> left -> right -> left = new BinaryTree(6); 
    root1 -> right -> left  ->  left = new BinaryTree(1);
    
    BinaryTree* root2 = new BinaryTree(4);   /*        4        */
    root2 -> left = new BinaryTree(2);       /*       / \       */
    root2 -> right = new BinaryTree(5);      /*      2   5      */
    root2 -> left -> left = new BinaryTree(1);/*    / \ / \     */
    root2 -> left -> right = new BinaryTree(1);/*  1  1 2  3    */
    root2 -> right -> left = new BinaryTree(2); /*    / /        */
    root2 -> right -> right = new BinaryTree(3); /*  6  1        */
    root2 -> left -> right -> left = new BinaryTree(6); 
    root2 -> right -> left  ->  left = new BinaryTree(1);
    

    if(identicalTrees(root1, root2))  
        cout << "Both tree are identical.";  
    else
        cout << "Trees are not identical.";  
  
    return 0;  
    



}