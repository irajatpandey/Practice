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
    if(!root) 
        return -1;
    int leftSubTreeHeight  = height(root -> left);
    int rightSubTreeHeight = height(root -> right);  

    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}
bool checkMirrorTree(BinaryTree<int> *root1, BinaryTree<int> *root2){
    if(root1 == NULL and root2 == NULL)
        return true;  
    if(root1 == NULL or root2 == NULL)
        return false;
    

    return (root1 -> data == root2 -> data) and checkMirrorTree(root1 -> left, root2 -> right) 
            and checkMirrorTree(root1 -> right, root2 -> left);
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
    //BinaryTree<int> *root = takeInput();

    BinaryTree<int>* root2 = new BinaryTree<int>(4);     
    root2->right = new BinaryTree<int>(2);                 
    root2->left = new BinaryTree<int>(5);                
    root2->right->right = new BinaryTree<int>(7);         
    root2->right->left = new BinaryTree<int>(1);          
    root2->left->right = new BinaryTree<int>(2);         
    root2->left->left = new BinaryTree<int>(3);         
    root2->right->left->right = new BinaryTree<int>(6); 
    root2->left->right -> right = new BinaryTree<int>(1);
    if(checkMirrorTree(root, root2))
        cout << "Yes\n";
    else
        cout << "No\n";    
    return 0;
}