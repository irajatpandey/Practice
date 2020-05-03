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

bool isIsomorphic(BinaryTree *root1, BinaryTree *root2){
    
}

int main() 
{ 
    // Let us create trees shown in above diagram 
    BinaryTree *n1 = new BinaryTree(1); 
    n1->left        = new BinaryTree(2); 
    n1->right       = new BinaryTree(3); 
    n1->left->left  = new BinaryTree(4); 
    n1->left->right = new BinaryTree(5); 
    n1->right->left  = new BinaryTree(6); 
    n1->left->right->left = new BinaryTree(7); 
    n1->left->right->right = new BinaryTree(8); 
  
    BinaryTree *n2 = new BinaryTree(1); 
    n2->left         = new BinaryTree(3); 
    n2->right        = new BinaryTree(2); 
    n2->right->left   = new BinaryTree(4); 
    n2->right->right   = new BinaryTree(5); 
    n2->left->right   = new BinaryTree(6); 
    n2->right->right->left = new BinaryTree(8); 
    n2->right->right->right = new BinaryTree(7); 
  
    if (isIsomorphic(n1, n2) == true) 
       cout << "Yes"; 
    else
      cout << "No"; 
  
    return 0; 
} 