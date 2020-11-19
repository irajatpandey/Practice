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
bool isBST(BinaryTree<int>* root, BinaryTree<int>* &prev)
{
    // base case: empty tree is a BST
    if (root == nullptr)
        return true;
    // check if left subtree is BST or not
    bool left = isBST(root->left, prev);
    // value of current node should be more than that of previous node
    if (root->data <= prev->data)
        return false;
    // update previous node and check if right subtree is BST or not
    prev = root;
    return left && isBST(root->right, prev);
}
void checkBST(BinaryTree<int>* root)
{
    // pointer to store previous processed node in inorder traversal
    BinaryTree<int>* prev = new BinaryTree<int>(INT_MIN);
    // check if nodes are nodes are processed in sorted order
    if (isBST(root, prev))
        printf("This is a BST.");
    else
        printf("This is NOT a BST!");
}




bool isBinarySearchTree(BinaryTree<int> *root, int min, int max){
    if(root == NULL) return true;
    
    if(min > root -> data) return false;
    if(max < root -> data) return false;
    

    return isBinarySearchTree(root -> left, min, root -> data) and 
    isBinarySearchTree(root -> right, root -> data , max);
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
    root->left->left = new BinaryTree<int>(1);           /*     / \ / \     */
    root->left->right = new BinaryTree<int>(3);          /*    7  1 2  3    */
    // root->right->left = new BinaryTree<int>(2);          /*      / /        */
    // root->right->right = new BinaryTree<int>(3);         /*     6 1         */
    // root->left->right->left = new BinaryTree<int>(6); 
    // root->right->left -> left = new BinaryTree<int>(1);
   
    int min = INT_MIN;
    int max = INT_MAX;
   
    if(isBinarySearchTree(root, min, max))
        cout << "Yes\n";
    else
        cout << "No\n";    
    return 0;
}