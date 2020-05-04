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
int height(BinaryTree *root){
  if(root == NULL) return 0;
  return 1 + max(height(root -> left), height(root -> right));
}


/*Time Complexity is O(n)*/
pair<int,int> diameterOptimal(BinaryTree *root){
 


}
/*Time Complexity is O(n * h) where h is height of the tree*/
int diameter(BinaryTree *root){
  
}

int main(){

    BinaryTree* root = new BinaryTree(4);   /*        4        */
    root->left = new BinaryTree(2);         /*       / \       */
    root->right = new BinaryTree(5);        /*      2   5      */
    root->left->left = new BinaryTree(1);   /*     / \ / \     */
    root->left->right = new BinaryTree(1);  /*    1  1 2  3    */
    root->right->left = new BinaryTree(2);  /*      / /        */
    root->right->right = new BinaryTree(3); /*     6  1        */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);
    
    cout << "Diameter of the given binary tree is " << diameter(root) << endl;
    pair<int,int> output = diameterOptimal(root);
    cout << "Diameter of the given binary Tree is : " << output.second << endl;
    return 0;



}
