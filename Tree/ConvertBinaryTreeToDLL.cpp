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

BinaryTree* convertBinaryTreeIntoDLL(BinaryTree *root){
     
}

void printList(BinaryTree *head){
    if(!head) return;

    while(head != NULL){
        cout << head -> data << " ";
        head = head -> right;
    }
}




int main(){

    BinaryTree *root  = new BinaryTree(10); 
    root->left        = new BinaryTree(12); 
    root->right       = new BinaryTree(15); 
    root->left->left  = new BinaryTree(25); 
    root->left->right = new BinaryTree(30); 
    root->right->left = new BinaryTree(36); 
    printList(convertBinaryTreeIntoDLL(root));
   

}