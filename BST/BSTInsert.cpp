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
        void printTree(){
            printTree(root);
        }
};



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
    root.insert(20);
    
    
    root.printTree();
    return 0;
}