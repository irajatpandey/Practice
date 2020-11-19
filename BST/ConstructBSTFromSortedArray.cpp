#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinarySearchTree{
    public:
        T data;
        BinarySearchTree *left;
        BinarySearchTree *right;

        BinarySearchTree(T data){
            this -> data = data;
            left = right = NULL;
        }
};
BinarySearchTree<int> *constructBSTHelper(int low, int high, vector<int> v){
      if(high < low) return NULL;
      int mid = (low + high)/2;
      BinarySearchTree<int> *root = new BinarySearchTree<int>(v[mid]);
      root -> left = constructBSTHelper(low, mid - 1, v);
      root -> right = constructBSTHelper(mid + 1, high, v);
      return root;  
}
BinarySearchTree<int> *constructBSTFromSortedArray(vector<int> v){
   
     return constructBSTHelper( 0, v.size() - 1, v);
}
void printTree(BinarySearchTree<int> *root){
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
    /* Construct below BST
              40
            /    \
           /      \
          20       60
         /  \     /  \
        /    \   /    \
       10    30 50    70
    */
 
    vector<int> v{10, 20, 30, 40, 50, 60, 70};
    BinarySearchTree<int> *root = constructBSTFromSortedArray(v);
    if(root == nullptr) cout << "Hello" << endl;
    printTree(root);
    
   
 
    return 0;
}