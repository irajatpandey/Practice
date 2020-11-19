#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTree{
    public:
    int data;
    BinaryTree<T> *left, * right, *rightNext;

    BinaryTree(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
        rightNext = NULL;
    }

};
void linkNode(BinaryTree<int> *root, int level, unordered_map<int,vector<BinaryTree<int>*>> &map){
    if(!root) return;
    map[level].push_back(root);
    linkNode(root -> left, level + 1, map);
    linkNode(root -> right, level + 1, map);

}

BinaryTree<int> *connectLinkNode(BinaryTree<int> *root){
    if(!root) return;
    unordered_map<int,vector<BinaryTree<int>*>> map;
    linkNode(root, 1, map);

    for(auto it : map){
        for(int i = 0; i < it.second.size(); i++){
                if(i != it.second.size() - 1){
                     it.second[i] -> rightNext = it.second[i+1];
                }
                else{
                    it.second[i] -> rightNext = NULL;
                }
        }
    }
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
/*     10                 10 ------> NULL
      / \               /    \
     3   5       =>    3 ----->5 --------> NULL
    / \   \          /  \       \
   4   1   2        4 --> 1 -----> 2 -------> NULL */


   /* 
              10            10 ----> NULL
             /   \         /  \
            20   30       20-->30---->NULL
           /  \          /  \
          40  60        40-->60------>NULL  
 
 
    */ 
    /* Construct below Tree
           1
         /   \
        2     3
       / \     \
      4   5     6
       \       /
        7     8
    */
 
    BinaryTree<int>* root = new BinaryTree<int>(1);
    root->left = new BinaryTree<int>(2);
    root->right = new BinaryTree<int>(3);
    root->left->left = new BinaryTree<int>(4);
    root->left->right = new BinaryTree<int>(5);
    root->right->right = new BinaryTree<int>(6);
    root->left->left->right = new BinaryTree<int>(7);
    root->right->right->left = new BinaryTree<int>(8);
    
    return 0;
}
