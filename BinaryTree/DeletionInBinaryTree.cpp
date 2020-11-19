/*Given a binary tree, delete a node from it by making sure that tree shrinks from the bottom 
(i.e. the deleted node is replaced by bottom most and rightmost node). */
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
void inorderTraversal(BinaryTree *root){
	if(root == NULL) return;
	inorderTraversal(root -> left);
	cout << root -> data << " ";
	inorderTraversal(root -> right);
}

void deletion(BinaryTree *root, int key){
	
}

int main(){
/*
		    13
		  /    \
		 12    10
		/  \   / \
	       4   19 16  9

	   		|
			|
			V


	            13
		  /    \
		 9     10
		/  \   / \
	       4   19 16  9

	   		|
			|
			V


	  	    13
		  /    \
		 9     10
		/  \   / 
	       4   19 16 	 


*/
	BinaryTree *root = new BinaryTree(13);
	root -> left = new BinaryTree(12);
	root -> right = new BinaryTree(10);
	root -> left -> left = new BinaryTree(4);
	root -> left -> right = new BinaryTree(19);
	root -> right -> left = new BinaryTree(16);
	root -> right -> right = new BinaryTree(9);

	deletion(root, 12);
	inorderTraversal(root);


	return 0;
}
