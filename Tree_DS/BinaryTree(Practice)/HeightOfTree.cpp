#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTree{
     public:
     T data;
     BinaryTree<T> *left;
     BinaryTree<T> *right;

     BinaryTree(T data){
         this -> data = data;
         left = NULL;
         right = NULL;
     }
};
int height(BinaryTree<int> *root){
    if(root == NULL) return 0;
    int left_height = height(root -> left);
    int right_height = height(root -> right);
    return max(left_height, right_height) + 1;
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
    cout << "height of binary Tree is : " << height(root);
    return 0;
}