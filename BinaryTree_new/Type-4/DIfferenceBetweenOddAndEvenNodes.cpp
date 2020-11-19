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
/* Find the difference between sum of all nodes present at odd and even levels in a binary tree
Given a binary tree, calculate the difference between sum of all nodes present at odd levels and sum of all nodes present at even level. */
void findDifference(BinaryTree<int> *root, int level, int &diff){
    if(!root) return;
    if(level % 2 != 0)
        diff = diff + root -> data;
    else
        diff -= root -> data;
    findDifference(root -> left, level + 1, diff);        
    findDifference(root -> right, level + 1, diff);        
}

int differenceBetweenEvenAndOddLevel(BinaryTree<int> *root){
    if(root == nullptr) return 0;
    int diff = 0;

    findDifference(root, 1, diff);

    return diff;
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
         /      /  \
        /      /    \
       4      5      6
             / \
            /   \
           7     8


           For example, consider below binary tree. The required difference is
                (1 + 4 + 5 + 6) – (2 + 3 + 7 + 8) = -4
    */
 
    root = new BinaryTree<int>(1);
    root->left = new BinaryTree<int>(2);
    root->right = new BinaryTree<int>(3);
    root->left->left = new BinaryTree<int>(4);
    root->right->left = new BinaryTree<int>(5);
    root->right->right = new BinaryTree<int>(6);
    root->right->left->left = new BinaryTree<int>(7);
    root->right->left->right = new BinaryTree<int>(8);
 
    cout << differenceBetweenEvenAndOddLevel(root);
 
    return 0;

   
    
 
    return 0;
}
