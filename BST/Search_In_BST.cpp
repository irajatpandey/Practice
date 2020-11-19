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
/* We don't need to go for each node we have to just check whether target lies left side or right side */
BinarySearchTree<int> *search(BinarySearchTree<int> *root, int target){
    if(!root) return NULL;
    if(root -> data == target) return root;
    
    if(root -> data > target)
        return search(root -> left, target);

    return search(root -> right, target);
   
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
 
    BinarySearchTree<int> *smallOutput = search(root, 12);
    cout << smallOutput -> data << endl;
    return 0;
}