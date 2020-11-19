/*  https://leetcode.com/problems/binary-tree-level-order-traversal */
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTree{
    public:
    int data;
    BinaryTree<T> *left, * right;

    BinaryTree(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};
/*This is Iterative Approach to print the given Binary Tree in Level Order Traversal*/

void printLevelOrderIterative(BinaryTree<int> *root){
    if(root == NULL) return;

    queue<BinaryTree<int>*> q;
    q.push(root);
    while(!q.empty()){
       BinaryTree<int> *temp = q.front();
       q.pop();
       if(temp -> left) q.push(temp -> left);
       if(temp -> right) q.push(temp -> right);
       cout << temp -> data << " ";
    }
}
/*This is Recursive Approach to print the given Binary Tree in Level Order Traversal*/
int height(BinaryTree<int> *root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}
void printTreeLevelWise(BinaryTree<int> *root, int level){
    if(root == NULL)
        return;
    if(level == 1)
        cout << root -> data << " ";
    printTreeLevelWise(root -> left, level - 1);        
    printTreeLevelWise(root -> right, level - 1);        
}
void printLevelOrder(BinaryTree<int> *root){
    if(root == NULL)
        return;
    int h = height(root);    
    for(int i = 1; i <= h; i++){
        printTreeLevelWise(root, i);
        cout << endl;

    }
      
}


void printTree(BinaryTree<int> *root){
    if(root == NULL) return;
    cout << root -> data << " : ";
    if(root -> left)
        cout << "L " << root -> left -> data << " ";
    if(root -> right)
        cout << "R " << root -> right -> data << " ";
    cout << endl;    
    printTree(root -> left);        
    printTree(root -> right);        
}
int main(){

    BinaryTree<int>* root = new BinaryTree<int>(4);      /*        4        */
    root->left = new BinaryTree<int>(2);                 /*       / \       */
    root->right = new BinaryTree<int>(5);                /*      2   5      */
    root->left->left = new BinaryTree<int>(7);           /*     / \ / \     */
    root->left->right = new BinaryTree<int>(1);          /*    7  1 2  3    */
    root->right->left = new BinaryTree<int>(2);          /*      / /        */
    root->right->right = new BinaryTree<int>(3);         /*     6 1         */
    root->left->right->left = new BinaryTree<int>(6); 
    root->right->left -> left = new BinaryTree<int>(1);
   
  
 
   printLevelOrder(root);
   
    return 0;
}