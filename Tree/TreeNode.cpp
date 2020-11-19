#include<bits/stdc++.h>
using namespace std;
template<typename T> 
class TreeNode{
    public:
    int data;
    vector<TreeNode <T>*> child;
    TreeNode(T data){
        this -> data = data;
    }
};
int heightOfTree(TreeNode<int> *root){
    if(root == NULL) return 0;
    int height = 0;

    for(int i = 0; i < root -> child.size(); i++){
        int treeHeight = heightOfTree(root -> child[i]);
        if(treeHeight > height)
            height = treeHeight;
         
    }
    return height + 1;
}
int countNodes(TreeNode<int>* root){
    if(root == NULL) return 0;
    int ans = 1; 
    for(int i = 0; i < root -> child.size(); i++)
        ans += countNodes(root -> child[i]);
    return ans;    
}
TreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter the root data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int> *f = q.front();
        q.pop(); int n;
        cout << "Enter the children of " << f -> data << endl;
        cin >> n;
        for(int i = 1; i <= n; i++){
            int childData;
            cout << "Enter the " << i << " th child of " << f -> data << endl;
            cin >> childData;
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            q.push(childNode);
            f -> child.push_back(childNode);
        }
    }
    return root;

}
TreeNode<int> *takeInput(){
    cout << "Enter data " << endl;
    int rootData;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter the number of Children of " << rootData << endl;
    cin >> n;

    for(int i = 1; i <= n; i++){
        TreeNode<int> *child = takeInput();
        root -> child.push_back(child);
    }
    return root;

}
void printTree(TreeNode<int> * root){

    cout << root -> data << " : ";
    for(int i = 0; i < root -> child.size(); i++)
        cout << root -> child[i] -> data << " ";
    cout << endl;    
    for(int i = 0; i < root -> child.size(); i++)
        printTree(root -> child[i]);

}
void printTreeLevelWise(TreeNode<int> * root){
    if(root == NULL) return;

    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();
        cout << f -> data << " : ";
        for(int i = 0; i < f -> child.size(); i++){
            cout << f -> child[i] -> data << " ";
            q.push(f -> child[i]);
            
        }
        cout << endl;
        
    }
}
int main(){
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *n1 = new TreeNode<int>(2);
    // TreeNode<int> *n2 = new TreeNode<int>(3);

    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << "Number of Nodes :" << countNodes(root)   << endl;
    cout << "Height of Tree :"  << heightOfTree(root) << endl;
    return 0;
}