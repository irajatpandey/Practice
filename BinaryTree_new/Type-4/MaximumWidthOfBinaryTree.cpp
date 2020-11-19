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
void level(BinaryTree<int> *root, int l, unordered_map<int,int> &map){
    if(!root) return;

    map[l]++;
    level(root -> left, l + 1, map);
    level(root -> right, l + 1, map);
}
int maximumWidth(BinaryTree<int> *root){
    if(root == NULL) return 0;
    unordered_map<int,int> map;

    level(root, 1, map);
    int ans = 0;
    for(auto it : map){
        ans = max(ans, it.second);
    }
    return ans;
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

    BinaryTree<int>* root = new BinaryTree<int>(1);   
    root->left = new BinaryTree<int>(2);                
    root->right = new BinaryTree<int>(3);                             
    root->left->left = new BinaryTree<int>(4);          
    root->left->right = new BinaryTree<int>(5);          
    root->right->right = new BinaryTree<int>(8);          
    root->right->right->left = new BinaryTree<int>(6);        
    root->left->right->left = new BinaryTree<int>(7); 
    /*   Constructed Binary tree is: 
                 1 
               /   \        
             2      3 
           /  \      \ 
          4    5      8 
                    /   \ 
                   6     7    */

/*  width of level 1 is 1,
    width of level 2 is 2,
    width of level 3 is 3
    width of level 4 is 2 */


    cout << maximumWidth(root);
    return 0;
}