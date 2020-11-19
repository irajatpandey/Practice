/*For every node, data value must be equal to sum of data values in left and right children*/
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

bool isSumProperty(BinaryTree *root){
	
}
int main(){
	BinaryTree *root = new BinaryTree(10); 
    root->left     = new BinaryTree(8); 
    root->right = new BinaryTree(2); 
    root->left->left = new BinaryTree(3); 
    root->left->right = new BinaryTree(5); 
    root->right->right = new BinaryTree(2); 

    if(isSumProperty(root)) 
        cout << "The given tree satisfies "
             << "the children sum property "; 
    else
        cout << "The given tree does not satisfy "
             << "the children sum property "; 
} 