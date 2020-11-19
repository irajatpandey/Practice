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
void spiralOrder(BinaryTree<int> *root){
     if(!root) return;

     stack<BinaryTree<int>*> s1, s2;
     s1.push(root);

     while(s1.size() > 0 or s2.size() > 0){

         while(s1.size() > 0){
            BinaryTree<int> *temp = s1.top(); 
            s1.pop();
            cout << temp -> data << " ";
            if(temp -> left) s2.push(temp -> left);
            if(temp -> right) s2.push(temp -> right);

         }

         while(s2.size() > 0){
            BinaryTree<int> *temp = s2.top(); 
            s2.pop();
            cout << temp -> data << " ";
            if(temp -> right) s1.push(temp -> right);
            if(temp -> left) s1.push(temp -> left);

         }
     }
}
int height(BinaryTree<int> *root){
    if(!root) return 0;

    return max(height(root -> left), height(root ->right)) + 1;
}
int diameter(BinaryTree<int> *root){
    if(root == NULL) return 0;

    int answerViaRoot = height(root -> left) + height(root -> right);
    int answerViaLeftSubTree = diameter(root -> left);
    int answerViaRightSubTree = diameter(root -> right);

    return max(answerViaRoot, max(answerViaLeftSubTree,answerViaRightSubTree));

}

pair<int,int> diameterOptimal(BinaryTree<int> *root){
    if(!root){
        // return {0,0}
        pair<int,int> p;
        p.first = 0; // height
        p.second = 0;   // diameter
        return p;
    }

    pair<int,int> leftDiameter = diameterOptimal(root -> left);
    pair<int,int> rightDiameter = diameterOptimal(root -> right);

    int leftHeight = leftDiameter.first;
    int leftSubTreeDiameter = leftDiameter.second;

    int rightHeight = rightDiameter.first;
    int rightSubTreeDiameter = rightDiameter.second;

    int height = 1 + max(leftHeight, rightHeight);
    int diameter = max(leftHeight + rightHeight, max(leftSubTreeDiameter, rightSubTreeDiameter));

    return {height, diameter};

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

    BinaryTree<int>* root = new BinaryTree<int>(4);      /*        4        */
    root->left = new BinaryTree<int>(2);                 /*       / \       */
    root->right = new BinaryTree<int>(5);                /*      2   5      */
    root->left->left = new BinaryTree<int>(7);           /*     / \ / \     */
    root->left->right = new BinaryTree<int>(1);          /*    7  1 9  3    */
    root->right->left = new BinaryTree<int>(9);          /*      / /        */
    root->right->right = new BinaryTree<int>(3);         /*     6 8         */
    root->left->right->left = new BinaryTree<int>(6); 
    root->right->left -> left = new BinaryTree<int>(8);
    
    cout << "Diameter of this Tree is : " << diameter(root) << endl; // answer : 6

    cout << "Optiamal Diameter function : " << diameterOptimal(root).first << endl;
    cout << "Optiamal Diameter function : " << diameterOptimal(root).second << endl;
    return 0;
}