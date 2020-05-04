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


void printRightViewOptimal(BinaryTree *root, int level, int *maxLevel){
   
}
void printRightView(BinaryTree *root, int level, map<int, int> &map){
  
}


// Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).
// Auxiliary Space: O(n), due to the stack space during recursive call.

void rightView(BinaryTree *root){
   
}

int main(){



    /*Right view of following tree is 1 3 7 8

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
                  \
                   8
                            */

    BinaryTree *root = new BinaryTree(1); 
    root -> left = new BinaryTree(2); 
    root -> right = new BinaryTree(3); 
    root -> left -> left = new BinaryTree(4); 
    root -> left -> right = new BinaryTree(5); 
    root -> right -> left = new BinaryTree(6); 
    root -> right -> right = new BinaryTree(7); 
    root -> right -> left -> right = new BinaryTree(8); 
  
    rightView(root);

}
