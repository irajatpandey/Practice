/*  https://leetcode.com/problems/binary-tree-level-order-traversal */
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
int height(BinaryTree<int> *root){
    if(root == NULL) return 0;
    int left_height = height(root -> left);
    int right_height = height(root -> right);
    return max(left_height, right_height) + 1;
}
void printReverseLevelOrderUsingRecursion(BinaryTree<int> *root, int level){
    if(root == NULL) return;
    if(level == 1) cout << root -> data << " ";
    if(level > 1){
        printReverseLevelOrderUsingRecursion(root -> left, level - 1);
        printReverseLevelOrderUsingRecursion(root -> right, level - 1);
    }
}
void reverseLevelOrderUsingRecursion(BinaryTree<int> *root){
    if(root == NULL) return;
    int h = height(root);
    for(int i = h; i >= 1; i--){
        printReverseLevelOrderUsingRecursion(root, i);
        cout << endl;
    }
}

/* ...................................Iterative Approach........................................................................ */
void printReverseLevelOrderUsingIteration(BinaryTree<int> *root){
     if(root == NULL) return; 
}
void reverseLevelOrderUsingIteration(BinaryTree<int> *root){
    if(root == NULL) return;
    queue<BinaryTree<int>*> q;
    stack<int> s;

    q.push(root);

    while(!q.empty()){
        BinaryTree<int> *f = q.front();
        q.pop();

        s.push(f->data);
        if(f -> right) q.push(f -> right);
        if(f -> left) q.push(f -> left);

    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
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
   
  
    reverseLevelOrderUsingRecursion(root);
    cout << endl;
    reverseLevelOrderUsingIteration(root);
   
    return 0;
}