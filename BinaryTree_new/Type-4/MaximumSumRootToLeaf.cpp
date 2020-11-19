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
int maximumSumRootToLeaf(BinaryTree<int> *root){
    if(root == NULL) return 0;
    int leftSum = maximumSumRootToLeaf(root -> left);
    int rightSum = maximumSumRootToLeaf(root -> right);

    return root -> data + max(leftSum, rightSum);
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

 BinaryTree<int>* root = nullptr;
    /* Construct below tree
              1
            /   \
           /     \
          2       3
         / \     / \
        8   4   5   6
           /   / \   \
         10   7   9   5
    */
 
    root = new BinaryTree<int>(1);
    root->left = new BinaryTree<int>(2);
    root->right = new BinaryTree<int>(3);
    root->left->left = new BinaryTree<int>(8);
    root->left->right = new BinaryTree<int>(4);
    root->right->left = new BinaryTree<int>(5);
    root->right->right = new BinaryTree<int>(6);
    root->left->right->left = new BinaryTree<int>(10);
    root->right->left->left = new BinaryTree<int>(7);
    root->right->left->right = new BinaryTree<int>(9);
    root->right->right->right = new BinaryTree<int>(5);
 
    
    cout << maximumSumRootToLeaf(root);
    return 0;
}