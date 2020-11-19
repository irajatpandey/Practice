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
    We can improve time complexity to O(n) by traversing the tree in bottom-up manner where an information is exchanged between the child nodes and parent node which helps in determining if subtree rooted under any node is a BST or not in O(1) time.

    * We know that a binary tree is a BST if following properties holds true for every tree node –

    * Left and right subtrees of every tree node are BST.
    
    * The value of a node should be more than the largest value in the left subtree and less than the smallest value in the right subtree.
      So to determine if a subtree rooted under a node is a BST or not, the left subtree should provide information about the maximum value in it and the right subtree should provide information about the minimum value in it. 
      Also, parent node should be notified when both left and right child are also BST.

*/
class SubTree{
    public:
        int min;
        int max;
        int size;
        bool isBST;

        SubTree(int min, int max, int size, bool isBST){
            this -> min = min;
            this -> max = max;
            this -> size = size;
            this -> isBST = isBST;
        }
};

SubTree *findLargestBST(BinaryTree<int> *root){
    if(root == NULL) 
        return new SubTree(INT_MAX, INT_MIN, 0, true);
    SubTree *left = findLargestBST(root -> left);    
    SubTree *right = findLargestBST(root -> right);   
    SubTree *info = NULL;
    if (left->isBST && right->isBST &&(root->data > left->max && root->data < right->min))
        info = new SubTree(min(root->data, min(left->min, right->min)),max(root->data, max(left->max, right->max)),(left->size + 1 + right->size),true);
    
    else
        info = new SubTree(0, 0,max(left->size, right->size),false);
    
    delete(left),delete(right);
    return info;
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

    /* Construct below binary tree

			  10
			/	\
		   /	  \
		  15	   8
		 / \	  / \
		/   \	/   \
	   12   20  5	 9
	  / \	  / \	 \
	 /   \	/   \	 \
	2	 14 4	 7	 10
	*/
 
    BinaryTree<int>* root = new BinaryTree<int>(10);
 
    root->left = new BinaryTree<int>(15);
    root->right = new BinaryTree<int>(8);
 
    root->left->left = new BinaryTree<int>(12);
    root->left->right = new BinaryTree<int>(20);
 
    root->right->left = new BinaryTree<int>(5);
    root->right->right = new BinaryTree<int>(9);
    root->left->left->left = new BinaryTree<int>(2);
	root->left->left->right = new BinaryTree<int>(14);
	root->right->left->left = new BinaryTree<int>(4);
	root->right->left->right = new BinaryTree<int>(7);
	root->right->right->right = new BinaryTree<int>(10);

    /* SubTree* answer = findLargestBST(root);
    cout << "Min "  << answer -> min << endl;
    cout << "Max "  << answer -> max << endl;
    cout << "Size " << answer -> size << endl; */
	cout << "The size of the largest BST is " << findLargestBST(root)->size;

    return 0;
}