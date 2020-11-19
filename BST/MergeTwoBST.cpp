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

void inorder(BinaryTree<int> *root, vector<int> &v){
    if(!root) return;
    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);

}
vector<int> merge(vector<int> v1, vector<int> v2){  
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> ans;
    while(i < v1.size() and j < v2.size()){
        if(v1[i] > v2[j]){
            ans.push_back(v2[j++]);
        }
        else
            ans.push_back(v1[i++]);
    }

    while(i <= v1.size() - 1) ans.push_back(v1[i++]);
    while(j <= v2.size() - 1) ans.push_back(v2[j++]);

    return ans;
}
 BinaryTree<int>* constructBSTFromSortedVector(vector<int> ans, int l, int h){
     if(l > h) return NULL;

    int mid = (l + h)/2;
    BinaryTree<int> *root = new BinaryTree<int>(ans[mid]);
    root->left = constructBSTFromSortedVector(ans, l, mid - 1);
    root->right = constructBSTFromSortedVector(ans, mid + 1, h);
    return root;
 }
BinaryTree<int> *mergeTwoBST(BinaryTree<int> *root1, BinaryTree<int> *root2){
    vector<int> v1;
    vector<int> v2;

    inorder(root1, v1);
    inorder(root2, v2);

    vector<int> ans = merge(v1,v2);

    return constructBSTFromSortedVector(ans, 0, ans.size() - 1);
    
}


int main(){
 
    BinarySearchTree root1;
    root1.insert(5);
    root1.insert(2);
    root1.insert(8);
    root1.insert(1);
    root1.insert(6);
    root1.insert(9);
    
   
   BinarySearchTree root2;
   root2.insert(7);
   root2.insert(3);
   root2.insert(10);

   root1.root = mergeTwoBST(root1.root, root2.root); 
   root1.printTree();
    
    return 0;
}