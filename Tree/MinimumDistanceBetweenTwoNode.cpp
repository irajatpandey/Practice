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
int getDistanceFromParentToNode(BinaryTree* root, int n, int dist){
	
}
int minmumDistanceBetweenTwoNode(BinaryTree*root, int n1, int n2){

}

int main(){

    BinaryTree* root = new BinaryTree(4);   /*        4        */
    root->left = new BinaryTree(2);         /*       / \       */
    root->right = new BinaryTree(5);        /*      2   5      */
    root->left->left = new BinaryTree(1);   /*     / \ / \     */
    root->left->right = new BinaryTree(1);  /*    1  1 2  3    */
    root->right->left = new BinaryTree(2);  /*      / /        */
    root->right->right = new BinaryTree(3); /*     6  1        */
    root->left->right->left = new BinaryTree(6); 
    root->right->left -> left = new BinaryTree(1);
    
    cout << minmumDistanceBetweenTwoNode(root, 2, 5);
    return 0;
    



}