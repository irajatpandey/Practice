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
  if(root == NULL){
    pair<int,int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }

  pair<int,int> leftAns = diameterOptimal(root -> left);
  int leftHeight = leftAns.first;
  int leftDiameter = leftAns.second;

  pair<int,int> rightAns = diameterOptimal(root -> right);
  int rightHeight = rightAns.first;
  int rightDiameter = rightAns.second;

  int height = 1 + max(leftHeight, rightHeight);
  int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

  pair<int,int> p;
  p.first = height;
  p.second = diameter;

  return p;



}
/*Time Complexity is O(n * h) where h is height of the tree*/
int diameter(BinaryTree *root){
   if(root == NULL) return 0;

   int h = height(root -> left) + height(root -> right);
   int leftDiameter = diameter(root -> left);
   int rightDiameter = diameter(root -> right);

   return max(h,max(leftDiameter, rightDiameter));
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