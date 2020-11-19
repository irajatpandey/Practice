#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i,n) for(int i = 0; i < n; i++)
using namespace std;

class BinaryTree{
    public:
    BinaryTree *left, *right;
    int data;

    BinaryTree(int data){
        this -> data = data;
        left = right = NULL;
    }

};

int decryptTheCipherTree(BinaryTree *root){
    if(!root) return 0;
    int originalValue = root -> data;
    root -> data = decryptTheCipherTree(root -> left) + decryptTheCipherTree(root -> right);
    return originalValue;

}
BinaryTree *takeInput(){
    cout << "Enter data ";
    int rootData; cin >> rootData;

    if(rootData == -1)
        return NULL;
    BinaryTree *root = new BinaryTree(rootData);
    BinaryTree *leftChild = takeInput();   
    BinaryTree*rightChild = takeInput(); 
    root -> left = leftChild;
    root -> right = rightChild;
    return root;
}
void printTree(BinaryTree *root){
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
int main() {
   BinaryTree *root = NULL;
   root = takeInput();
   decryptTheCipherTree(root);
   printTree(root);

    return 0;
}