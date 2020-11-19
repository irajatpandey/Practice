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

/* Find size of the largest BST in a Binary Tree
Given a binary tree, find the size of the largest BST (Binary Search Tree) in it. */
int sizeOfBST(BinaryTree<int> *root){
    if(root == NULL) return 0;
    return 1 + sizeOfBST(root -> left) + sizeOfBST(root -> right);
}
bool isBST(BinaryTree<int> *root, int &min, int &max){
    if(root == NULL) return true;
    if(root -> data < min or root -> data > max)
        return false;
    return isBST(root -> left, min, root -> data) and isBST(root -> right, root -> data, max);
}      
/* The time complexity of this approach is O(n^2) and requires O(h) extra space for the call stack where h is the height of the tree */
int findLargestBST(BinaryTree<int> *root){
    int min = INT_MIN;
    int maximum = INT_MAX;
    if(isBST(root, min, maximum))
        return sizeOfBST(root);

    return max(findLargestBST(root -> left), findLargestBST(root -> right));    
}
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

      /* Construct below binary tree
 
              10
            /    \
           /      \
          15       8
         / \      / \
        /   \    /   \
       12   20  5     2
    */
 
    BinaryTree<int>* root = new BinaryTree<int>(10);
 
    root->left = new BinaryTree<int>(15);
    root->right = new BinaryTree<int>(8);
 
    root->left->left = new BinaryTree<int>(12);
    root->left->right = new BinaryTree<int>(20);
 
    root->right->left = new BinaryTree<int>(5);
    root->right->right = new BinaryTree<int>(2);

    cout << "Largest BST is : " << findLargestBST(root) << endl;
    return 0;
}