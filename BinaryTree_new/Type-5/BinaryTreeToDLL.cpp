#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTree{
    public:
    int data;
    BinaryTree<T> *left, * right, *rightNext;

    BinaryTree(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
        rightNext = NULL;
    }

};
void reverse(BinaryTree<int>*& head)
{
    BinaryTree<int>* prev = nullptr;
    BinaryTree<int>* current = head;
 
    while (current)
    {
        swap(current->left, current->right);
        prev = current;
        current = current->left;
    }
 
    if (prev != nullptr)
        head = prev;
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
void convert(BinaryTree<int> *root, BinaryTree<int> *&head,  BinaryTree<int> *&prev){
    if(!root) return;

    convert(root -> left, head, prev);

    if(prev == NULL){
       head = root;
    }
    else{
        root -> left = prev;
        prev -> right = root;
    }
    prev = root;
    convert(root -> right, head, prev);

}
BinaryTree<int> *binaryTreeToDLL(BinaryTree<int> *root, BinaryTree<int> *head){
    if(!root) return nullptr;
     BinaryTree<int> *prev = nullptr;
     convert(root, head, prev);
     return head;
}
void printDLL(BinaryTree<int>* &head)
{
    BinaryTree<int>* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}
 
int main(){

    
    /* Construct below tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
    */
 
    BinaryTree<int>* root = new BinaryTree<int>(1);
    root->left = new BinaryTree<int>(2);
    root->right = new BinaryTree<int>(3);
    root->left->left = new BinaryTree<int>(4);
    root->left->right = new BinaryTree<int>(5);
    root->right->left = new BinaryTree<int>(6);
    root->right->right = new BinaryTree<int>(7);
 
    BinaryTree<int> *head = binaryTreeToDLL(root, NULL);
    //reverse();_
    printDLL(head);

    return 0;
 
}
