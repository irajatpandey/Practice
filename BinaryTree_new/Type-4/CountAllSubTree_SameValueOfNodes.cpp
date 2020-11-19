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
// Count all subtrees having same value of nodes in a binary tree
/* Given a binary tree, count all subtrees in it such that every node in the subtree have same value. */

int countAllSubTreeWithSameNodes(BinaryTree<int> *root){
    

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

   /* Construct below tree
                 1
                / \
               /   \
              2     3
             /     / \
            /     /   \
           4     5     6
          /     / \     \
         /     /   \     \
        4     5     5     7
    */
    
    
    BinaryTree<int> *root = new BinaryTree<int>(1);
    root->left = new BinaryTree<int>(2);
    root->right = new BinaryTree<int>(3);
    root->left->left = new BinaryTree<int>(4);
    root->right->left = new BinaryTree<int>(5);
    root->right->right = new BinaryTree<int>(6);
    root->left->left->left = new BinaryTree<int>(4);
    root->right->left->left = new BinaryTree<int>(5);
    root->right->left->right = new BinaryTree<int>(5);
    root->right->right->right = new BinaryTree<int>(7);

    printTree(root);
 
    return 0;
}