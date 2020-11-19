#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinarySearchTree{
    public:
        T data;
        BinarySearchTree *left;
        BinarySearchTree *right;

        BinarySearchTree(T data){
            this -> data = data;
            left = right = NULL;
        }
};
template<typename T>
class LinkedList{
    public:
    T data;
    LinkedList *next;
    LinkedList(T data){
        this -> data = data;
        this -> next = NULL;
     
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    }
};


LinkedList<int>* head = nullptr;
LinkedList<int>* convertBSTtoLinkedList(BinarySearchTree<int> *root){
    if(root -> left == NULL and root -> right == NULL){
        LinkedList<int> *temp = new LinkedList<int>(root->data);
        return temp;
    }
    LinkedList<int> *left = convertBSTtoLinkedList(root -> left);
    LinkedList<int> *output = new LinkedList<int>(root -> data);
    LinkedList<int> *right = convertBSTtoLinkedList(root -> right);

    left -> next = output;
    output -> next = right;

    return left;

}

void printLinkedList(LinkedList<int> *head){
    if(!head) return;
    cout << "LinekdList : " << endl;
    while(head){
        cout << head -> data << " ";
        head = head -> next;
    }

}
void printTree(BinarySearchTree<int> *root){
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
  /* Construct below BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
 
    BinarySearchTree<int>* root = new BinarySearchTree<int>(15);
    root->left = new BinarySearchTree<int>(10);
    root->right = new BinarySearchTree<int>(20);
    root->left->left = new BinarySearchTree<int>(8);
    root->left->right = new BinarySearchTree<int>(12);
    root->right->left = new BinarySearchTree<int>(16);
    root->right->right = new BinarySearchTree<int>(25);
    
    LinkedList<int>* smallOutput = convertBSTtoLinkedList(root);
    printLinkedList(smallOutput);
    return 0;
}