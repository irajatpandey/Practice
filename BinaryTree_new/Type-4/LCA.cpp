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
/*
Approach 1 
This approach requires three traversal and the time complexity will be O(n) 
and the space complexity will be O(n)
*/
bool findPath(BinaryTree<int> *root, int n1, vector<BinaryTree<int> *> &v){
    if(root == NULL) return false;
    v.push_back(root);
    if(root -> data == n1) return true;

    if(findPath(root -> left, n1, v) or findPath(root -> right, n1 , v))
        return true;

    v.pop_back();
    return false;   
}


BinaryTree<int> *lca(BinaryTree<int> *root, int n1, int n2){
    
   
    vector<BinaryTree<int>*> v1, v2;
    
    if(findPath(root, n1, v1) == false or findPath(root, n2, v2) == false)
        return NULL;

    for(int i = 0; i < v1.size() - 1 and i < v2.size() - 1; i++){
        if(v1[i + 1] != v2[i + 1])
            return v2[i];
    }
    return NULL;
}

/* 
    Approach 2
    Using Single Traversal and the Space Complexity should be constant
*/


/*  Time complexity O(n)
 Space complexity O(h) */
BinaryTree<int> *leastCommonAncestor(BinaryTree<int> *root, int n1, int n2){
    if(!root) return root;
    BinaryTree<int> *lca1 = leastCommonAncestor(root -> left, n1, n2);
    BinaryTree<int> *lca2 = leastCommonAncestor(root -> right, n1, n2);
    if(root -> data == n1 or root -> data == n2)
        return root;
    if(lca1 != NULL and lca2 != NULL)
        return root;
    return lca1 != NULL ? lca1 : lca2;       

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
    root->left->right = new BinaryTree<int>(1);          /*    7  1 8  3    */
    root->right->left = new BinaryTree<int>(8);          /*      / /        */
    root->right->right = new BinaryTree<int>(3);         /*     6 9         */
    root->left->right->left = new BinaryTree<int>(6); 
    root->right->left -> left = new BinaryTree<int>(9);
   
    cout << lca(root, 1, 8) -> data << endl;
    cout << leastCommonAncestor(root, 5, 3) -> data << endl;
    return 0;
}