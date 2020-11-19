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
void printInRange(BinarySearchTree<int> *root, int leftValue, int rightValue){
    if(!root) return;

     if(leftValue < root -> data)
        printInRange(root -> left, leftValue, rightValue);
     if(leftValue <= root -> data and root -> data <= rightValue)
        cout << root -> data << " ";    
     if(rightValue >= root -> data)
        printInRange(root -> right, leftValue, rightValue);
;



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
 
    printInRange(root, 15, 20);
    return 0;
}