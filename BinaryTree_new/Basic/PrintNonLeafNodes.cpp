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
BinaryTree<int> *takeInput(){
    cout << "Enter data ";
    int rootData; cin >> rootData;

    if(rootData == -1)
        return NULL;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    BinaryTree<int> *leftChild = takeInput();   
    BinaryTree<int> *rightChild = takeInput(); 
    root -> left = leftChild;
    root -> right = rightChild;
    return root;
}
void printNonLeaf(BinaryTree<int> *root){\
    if(!root) return;
   if(root -> left != NULL or root -> right != NULL)
        cout << root -> data << " ";
    printNonLeaf(root -> left);    
    printNonLeaf(root -> right);    
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
    
    //BinaryTree<int> *root = takeInput();
    printTree(root);
    printNonLeaf(root);

    return 0;
}