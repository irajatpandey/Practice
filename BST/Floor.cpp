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
int floorInBST_Iterative(BinaryTree<int> *root, int x){
    int res =INT_MAX;
    while(root){
        if(root -> data == x) return x;
        else if(root -> data > x) root = root -> left;
        else {
            res = root -> data;
            root = root -> right;
        }
    }
    return res;
}
int floorInBST(BinaryTree<int> *root, int x){
    /* Recursive Function to find the floor in BST */
    /* Time Complexity : O(h)
        Space Complexity : o(h)  */
    if(root == NULL) return INT_MAX;

    if(root -> data == x){
        return root -> data;
    }

    if(root -> data > x){
        return floorInBST(root -> left, x); 
    }
    
    int ans = floorInBST(root -> right, x);
    return ans <= x ? ans : root -> data;

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
   
    cout <<"Floor value of 22 : "<< floorInBST(root.root,22) << endl;
    cout <<"Floor value of 20 : "<< floorInBST_Iterative(root.root,22) << endl;
    return 0;
}