#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTree{
     public:
     T data;
     BinaryTree<T> *left;
     BinaryTree<T> *right;

     BinaryTree(T data){
         this -> data = data;
         left = NULL;
         right = NULL;
     }
};
int sumOfNodes(BinaryTree<int> *root){
    if(root == NULL) return 0;
    int answer = root -> data + sumOfNodes(root -> left) + sumOfNodes(root -> right);
    return answer;

}
int countNodes(BinaryTree<int> *root){
    if(root == NULL) return 0;
    int answer = 1 + countNodes(root -> left) + countNodes(root -> right);
    return answer;

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
    cout << "Number of Nodes :" << countNodes(root) << endl;
    cout << "Sum of Nodes : "   << sumOfNodes(root) << endl;
    return 0;
}