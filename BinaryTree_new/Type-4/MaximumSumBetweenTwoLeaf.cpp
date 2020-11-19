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
/* This Problem is Similar to the Diameter of tree and we just need to modify it and we will achieve the desire output */
int maximumSumRootToLeaf(BinaryTree<int> *root){
    if(root == NULL) return 0;
    int leftSum = maximumSumRootToLeaf(root -> left);
    int rightSum = maximumSumRootToLeaf(root -> right);
    return root -> data + max(leftSum, rightSum);
}/* Time complexity of this approach is O(n^2) because we are calling maximumRootToLeaf on each node */
int maximumSumBetweenTwoLeaf(BinaryTree<int> *root){
    if(root == nullptr) return 0;
    int leftSubTree = maximumSumRootToLeaf(root -> left);
    int rightSubTree = maximumSumRootToLeaf(root -> right);
    return max(root -> data + leftSubTree + rightSubTree, max(maximumSumBetweenTwoLeaf(root -> left), maximumSumBetweenTwoLeaf(root -> right)));
}
/* Optimal Solution  */
int calculateMaxSum(BinaryTree<int> *root, int &maximum){
    if(root == NULL) return 0;

    int left = calculateMaxSum(root -> left, maximum);
    int right = calculateMaxSum(root -> right, maximum);
    if(root -> left and root -> right){
        maximum = max(maximum , root -> data + left + right);
        return max(left,right) + root -> data;
    }
    else{
        return (root -> left) ? left + root -> data : right + root -> data;
    }

    return max(left,right) + root -> data;
}
int maximumSumPathBetweenTwoLeaf(BinaryTree<int> *root){
    if(root == NULL) return 0;
    int maximum = INT_MIN;
    calculateMaxSum(root, maximum);
    return maximum;

}
BinaryTree<int> *takeInput(){
    cout << "Enter data ";
    int rootData; cin >> rootData;

    if(rootData == -1)
        return NULL;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    BinaryTree<int> *leftChild = takeInput();   
    BinaryTree<int> *rightChild = takeInput(); 
    root -> left = leftChild;
    root -> right = rightChild;
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
int main(){

    /* Construct below tree
          1
        /   \
       /     \
      2       3
       \     / \
       -4   5   6
           / \
          7   8
    */
 
/*     BinaryTree<int> *root = new BinaryTree<int>(1);
    root->left = new BinaryTree<int>(2);
    root->right = new BinaryTree<int>(3);
    root->left->right = new BinaryTree<int>(-4);
    root->right->left = new BinaryTree<int>(5);
    root->right->right = new BinaryTree<int>(6);
    root->right->left->left = new BinaryTree<int>(7);
    root->right->left->right = new BinaryTree<int>(8); */

    BinaryTree<int> *root = new BinaryTree<int>(3);
    root->left = new BinaryTree<int>(5);
    root->right = new BinaryTree<int>(6);
    root->left->left = new BinaryTree<int>(7);
    root->left->right = new BinaryTree<int>(8);


   
    cout << maximumSumBetweenTwoLeaf(root) << endl;
    int ans = maximumSumPathBetweenTwoLeaf(root);
    cout << "Maximum Sum Between Two Leaf Node : " << ans << endl; 
 
    return 0;
}
