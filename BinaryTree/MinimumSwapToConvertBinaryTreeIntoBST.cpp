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
void inorder(BinaryTree * root, vector<int> &v){

    if(!root) return;

    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);

}

int minimumSwap(vector<int> v){
    
   
}

// Time Complexity is O(nlogn)
// Space Complexity is O(n)
int swapCountToChangeInBST(BinaryTree *root){
    

}



int main(){

    BinaryTree *root = new BinaryTree(12); 
    root->left = new BinaryTree(5); 
    root->left->left = new BinaryTree(3); 
    root->left->right = new BinaryTree(9); 
    root->left->left->left = new BinaryTree(1); 
    root->left->right->left = new BinaryTree(1); 
    
    cout <<"Minimum Swap required to converet BinaryTree into BST is " << swapCountToChangeInBST(root);



}