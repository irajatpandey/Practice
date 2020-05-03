#include <bits/stdc++.h>
using namespace std;
class BinaryTree{
    public:
    int data;
    BinaryTree  *left, *right;

    BinaryTree(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
    
};


void levelOrder(BinaryTree *root){
    if(root == NULL) return;
     queue<BinaryTree *> q;

     q.push(root);
     while(!q.empty()){
        BinaryTree *temp = q.front();
        cout << temp -> data << " ";
        q.pop();

        if(temp -> left)
           q.push(temp -> left);
        if(temp -> right)
            q.push(temp -> right);

                    
     }

    
}
int main(){

    // binary tree formation 
    BinaryTree* root = new BinaryTree(4);   /*        4        */
    root->left = new BinaryTree(2);         /*       / \       */
    root->right = new BinaryTree(5);        /*      2   5      */
    root->left->left = new BinaryTree(1);   /*     / \ / \     */
    root->left->right = new BinaryTree(1);  /*    1  1 2  3    */
    root->right->left = new BinaryTree(2);  /*      / /        */
    root->right->right = new BinaryTree(3); /*     6  1        */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);
    
    levelOrder(root);



}