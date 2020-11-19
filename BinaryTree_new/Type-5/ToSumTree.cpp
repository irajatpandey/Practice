#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTree{
    public:
    int data;
    BinaryTree<T> *left, * right, *rightNext;

    BinaryTree(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
        rightNext = NULL;
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
void takeInorder(BinaryTree<int> *root, set<int> &s){
     if(!root) return;

     takeInorder(root -> left, s);
     s.insert(root -> data);
     takeInorder(root -> right, s); 
}
int calculateSum(BinaryTree<int> *root){
    if(!root) return 0;
    return root-> data + calculateSum(root -> left)+ calculateSum(root -> right);

}
/* Time complexity O(n^2) */
void sumTree(BinaryTree<int> *root){
    if(!root) return;
    int l = calculateSum(root -> left);
    int r = calculateSum(root -> right);
    root -> data = l + r;
    sumTree(root -> left);
    sumTree(root -> right);
}
int main(){

    
    /* Construct below tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
    */
 
    BinaryTree<int>* root = new BinaryTree<int>(1);
    root->left = new BinaryTree<int>(2);
    root->right = new BinaryTree<int>(3);
    root->left->left = new BinaryTree<int>(4);
    root->left->right = new BinaryTree<int>(5);
    root->right->left = new BinaryTree<int>(6);
    root->right->right = new BinaryTree<int>(7);
    sumTree(root);
    printTree(root);
    return 0;
 
}
