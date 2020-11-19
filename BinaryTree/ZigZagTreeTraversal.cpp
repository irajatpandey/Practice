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

void zizagtraversal(BinaryTree *root){
	
}

int main(){
	/*			1
			  /   \
			 2     3
			/ \	  /	\
		   7  6  5   4

	 output 1 3 2 7 6 5 4
    */

	BinaryTree* root = new BinaryTree(1); 
    root -> left = new BinaryTree(2); 
    root -> right = new BinaryTree(3); 
    root -> left -> left = new BinaryTree(7); 
    root -> left -> right = new BinaryTree(6); 
    root -> right -> left = new BinaryTree(5); 
    root -> right -> right = new BinaryTree(4); 
    cout << "ZigZag Order traversal of binary tree is \n"; 
  
    zizagtraversal(root); 
  
    return 0;
  
    
    



}
 