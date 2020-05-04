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
    if(root == NULL) return;
    if(level >= (*maxLevel)){
        cout << root -> data << " ";
        (*maxLevel)++;

    }

    printRightViewOptimal(root -> right, level + 1, maxLevel);
    printRightViewOptimal(root -> left, level + 1, maxLevel);
}
void printRightView(BinaryTree *root, int level, map<int, int> &map){
    if(root == NULL) return;

    if(map.find(level) == map.end()){
        map[level] = root -> data;
    }

    printRightView(root -> right, level + 1, map);
    printRightView(root -> left, level + 1, map);
}


// Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).
// Auxiliary Space: O(n), due to the stack space during recursive call.

void rightView(BinaryTree *root){
    map<int, int> map;
    // printRightView(root, 0, map);

    // for(auto i : map) cout << i.second << " ";
    // cout << endl;
    int maxLevel = 0;
    printRightViewOptimal(root, 0, &maxLevel);    
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