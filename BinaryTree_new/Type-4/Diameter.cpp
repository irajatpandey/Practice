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
int height(BinaryTree<int> *root){
    if(root == NULL) return 0;
    return 1 + max(height(root -> left), height(root -> right));

}
/* This is the better approach to solve the problem and the time complexity is O(n) */
pair<int,int> calculateDiameter(BinaryTree<int> *root){
    if(!root) return {0,0};

    pair<int,int> leftDiameter = calculateDiameter(root -> left);
    pair<int,int> rightDiameter = calculateDiameter(root -> right);

    int lh = leftDiameter.first;
    int rh = rightDiameter.first;

    int ld = leftDiameter.second;
    int rd = rightDiameter.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    return {height, diameter};

}
/* This is the brute force approach to solve the problem
    Time Complexity : O(n^2)            */
int diameter(BinaryTree<int> *root){
    if(!root) return 0;
    int output = height(root->left) + height(root->right);
    int leftDiameter = diameter(root -> left);
    int rightDiameter = diameter(root -> right);

    return max(output, max(leftDiameter, rightDiameter));
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

    BinaryTree<int>* root = new BinaryTree<int>(4);      /*        4        */
    root->left = new BinaryTree<int>(2);                 /*       / \       */
    root->right = new BinaryTree<int>(5);                /*      2   5      */
    root->left->left = new BinaryTree<int>(7);           /*     / \ / \     */
    root->left->right = new BinaryTree<int>(1);          /*    7  1 2  3    */
    root->right->left = new BinaryTree<int>(2);          /*      / /        */
    root->right->right = new BinaryTree<int>(3);         /*     6 1         */
    root->left->right->left = new BinaryTree<int>(6); 
    root->right->left -> left = new BinaryTree<int>(1);
    cout << diameter(root) << endl;
    cout << calculateDiameter(root).second << endl;
    return 0;
}