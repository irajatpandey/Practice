#include<bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;

class BinarySearchTree{
    public:
        BinaryTree<int> *root;
        BinarySearchTree(){
            root = NULL;
        }

    private:
        BinaryTree<int> *deleteBST(BinaryTree<int> *root, int data){
            if(root == NULL) return NULL;
            if(root -> data > data) root -> left = deleteBST(root -> left, data);
            else if(root -> data < data) root -> right = deleteBST(root -> right, data);

            else{
                if(root->left == NULL){
                    BinaryTree<int> *temp = root -> right;
                    delete root;
                    return temp;
                }
                if(root -> right == NULL){
                    BinaryTree<int> *temp = root -> left;
                    delete root;
                    return temp;
                }
                else{
                    BinaryTree<int> *temp = root -> right;
                    while(temp -> left != NULL){
                        temp = temp -> left;
                    }
                    root -> data = temp -> data;
                    root -> right = deleteBST(root -> right, temp -> data);

                }
            }
            return root;
        }
        BinaryTree<int> *insert(BinaryTree<int> *root, int data){
            if(!root){
                root = new BinaryTree<int>(data);
                return root;
            } 
            if(root -> data > data)
                root -> left = insert(root -> left, data);
            
            else
                root -> right = insert(root -> right, data);

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
    public:
        void insert(int data){
            this -> root = insert(this -> root, data);
        } 
        void deleteBST(int data){
            this -> root = deleteBST(root, data);
        }
        void printTree(){
            printTree(root);
        }
};
/* Two nodes of a BST are swapped, correct the BST
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.
Input Tree:
         10
        /  \
       5    8
      / \
     2   20

In the above tree, nodes 20 and 8 must be swapped to fix the tree.  
Following is the output tree
         10
        /  \
       5    20
      / \
     2   8 */

void inorder(BinaryTree<int> *root, BinaryTree<int> *&prev, BinaryTree<int> *&first, BinaryTree<int> *&second){
    if(!root) return;

    inorder(root -> left, prev, first, second);
    if(prev and prev -> data > root-> data){
        if(first == NULL){
            first = prev;
        }
        second = root;
    }
    prev = root;
    inorder(root -> right, prev, first, second);
}
BinaryTree<int> *correctBST(BinaryTree<int> *root){
    BinaryTree<int> *prev = NULL, *first = NULL, *second = NULL;

    inorder(root, prev, first, second);
    swap(first -> data, second -> data);
    return root;
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
 
    BinarySearchTree root;
    root.insert(15);
    root.insert(10);
    root.insert(20);
    root.insert(8);
    root.insert(12);
    root.insert(16);
    root.insert(25);
    swap(root.root -> left -> data, root.root -> right -> data);
    root.root = correctBST(root.root);
    root.printTree();

    
    
    return 0;
}