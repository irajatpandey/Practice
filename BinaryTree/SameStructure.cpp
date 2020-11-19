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

// Time Complexity O(n)
bool isSameStructure(BinaryTree *root1, BinaryTree *root2){
    if(root1 == NULL and root2 == NULL)
        return true;
    if(root1 == NULL or root2 == NULL)
        return false;

    return isSameStructure(root1 -> left, root2 -> left) and isSameStructure(root1 -> right, root2 -> right);        
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
    
    BinaryTree* root2 = new BinaryTree(41);   /*        41        */
    root2 -> left = new BinaryTree(21);       /*       /  \       */
    root2 -> right = new BinaryTree(51);      /*      21   51      */
    root2 -> left -> left = new BinaryTree(11);/*    / \   / \     */
    root2 -> left -> right = new BinaryTree(11);/*  11  11 21 31    */
    root2 -> right -> left = new BinaryTree(21); /*    /  /        */
    root2 -> right -> right = new BinaryTree(31); /*  61 11        */
    root2 -> left -> right -> left = new BinaryTree(61); 
    root2 -> right -> left  ->  left = new BinaryTree(11);
    

    if(isSameStructure(root1, root2))  
        cout << "Both trees have same structure.";  
    else
        cout << "Both trees have different structure.";  
  
    return 0;  
    



}
