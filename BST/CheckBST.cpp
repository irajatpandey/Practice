#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinarySearchTree{
    public:
        T data;
        BinarySearchTree *left;
        BinarySearchTree *right;

        BinarySearchTree(T data){
            this -> data = data;
            left = right = NULL;
        }
};
bool isBSTHelper(BinarySearchTree<int> *root, int minimum, int maximum){
    if(!root) return true;
    if(root -> data < minimum or root -> data > maximum) return false;
    return (root ->data > minimum and root -> data <= maximum) and isBSTHelper(root -> left, minimum, root -> data) and isBSTHelper(root -> right, root -> data, maximum);
}
bool isBST(BinarySearchTree<int> *root){
    if(!root) return true;
    int minimum = INT_MIN;
    int maximum = INT_MAX;
    return isBSTHelper(root, minimum, maximum);
}
int main(){

    /* Construct below BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
 
    BinarySearchTree<int>* root = new BinarySearchTree<int>(15);
    root->left = new BinarySearchTree<int>(10);
    root->right = new BinarySearchTree<int>(20);
    root->left->left = new BinarySearchTree<int>(8);
    root->left->right = new BinarySearchTree<int>(12);
    root->right->left = new BinarySearchTree<int>(16);
    root->right->right = new BinarySearchTree<int>(25);
 
    if(isBST(root)) cout << "BinaryTree is BST" << endl;
    else cout << "BinaryTree is not BST" << endl;


    cout << m << endl;
    return 0;
}