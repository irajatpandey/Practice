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
bool isBST(BinaryTree<int> *root, int min, int max){
     if(!root) return true;
     if(root -> data < min or root -> data > max)
        return false;
     return isBST(root -> left, min, root -> data) and isBST(root -> right, root -> data, max);
}
int sizeofBST(BinaryTree<int> *root){
    if(!root) return 0;

    int ans = 1 + sizeofBST(root -> left) + sizeofBST(root -> right);
    return ans;

}

int findLargestBST(BinaryTree<int> *root){
    if(!root) return 0;
    int min = INT_MIN;
    int maximum = INT_MAX;

    if(isBST(root,min,maximum))
        return sizeofBST(root);
        
    return max(findLargestBST(root -> left), findLargestBST(root -> right));
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

    BinaryTree<int>* root = nullptr;
 
    root = new BinaryTree<int>(20);
    root -> left = new BinaryTree<int>(15);
    root -> right = new BinaryTree<int>(25);
    root -> left -> left = new BinaryTree<int>(12);
    root -> left -> right = new BinaryTree<int>(18);
    root -> right -> left = new BinaryTree<int>(24);
    root -> right -> right = new BinaryTree<int>(230);
    root -> right -> right -> right = new BinaryTree<int>(231);
    root -> right -> right -> right -> right = new BinaryTree<int>(236);
    
 
    cout << findLargestBST(root);
   
    
 
    return 0;
}
