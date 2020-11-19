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
BinaryTree* findLCA(BinaryTree* root, int n1, int n2){
    
}


int main(){

             /*  1
               /   \
              2     3
             / \   / \  
            4   5 6   7
        */
    BinaryTree *root = new BinaryTree(1);                               
    root -> left = new BinaryTree(2);                                          
    root -> right = new BinaryTree(3);                                
    root -> left -> left = new BinaryTree(4);                         
    root -> left -> right = new BinaryTree(5);                      
    root -> right -> left = new BinaryTree(6); 
    root -> right -> right = new BinaryTree(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);    // 2
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6);  // 1
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4); // 1
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4);// 2



}