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
bool checkIdenticalTree(BinaryTree<int> *root1, BinaryTree<int> *root2){
    if(root1 == NULL and root2 == NULL)
        return true;  
    if(root1 == NULL or root2 == NULL)
        return false;
    

    return (root1 -> data == root2 -> data) and checkIdenticalTree(root1 -> left, root2 -> left) and checkIdenticalTree(root1 -> right, root2 -> right);
}
bool checkSubTree(BinaryTree<int> *root1, BinaryTree<int> *root2){
      if(root1 == NULL) return false;
      if(root2 == NULL) return false;

      if(root1 -> data != root2 -> data)
        return false;

      if(checkIdenticalTree(root1, root2))
        return true;  

      return checkSubTree(root1 -> left, root2) or checkSubTree(root1 -> right, root2);  
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
   
    BinaryTree<int>* root2 = new BinaryTree<int>(4);      /*        4        */
    root2->left = new BinaryTree<int>(2);                 /*       / \       */
    root2->right = new BinaryTree<int>(5);                /*      2   5      */
 
   
    if(checkSubTree(root, root2))
        cout << "Yes\n";
    else
        cout << "No\n";    
    return 0;
}