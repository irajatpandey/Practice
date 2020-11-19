#include<bits/stdc++.h>
using namespace std;
template<typename T>
class GenricTree{
    public:
        T data;
        vector<GenricTree<T>*> child;

        GenricTree(T data){
            this -> data = data;
        }
};
GenricTree<int>* takeInput(){
    int rootData;
    cout << "Enter data " << endl;
    cin >> rootData;

    GenricTree<int> *root = new GenricTree<int>(rootData);
    int numberOfChildren;
    cout << "Enter the number of children of " << rootData << endl;
    cin >> numberOfChildren;

    for(int i = 1; i <= numberOfChildren; i++){
        GenricTree<int> *child = takeInput();
        root -> child.push_back(child);
    }
    return root;

}
void printTree(GenricTree<int> *root){
    if(root == NULL) return;

    cout << root -> data << " : ";
    for(int i = 0; i < root -> child.size(); i++){
        cout << root -> child[i] -> data << " ";
    }
    cout << endl;
    for(int i = 0; i < root -> child.size(); i++)
        printTree(root -> child[i]);
}
int main(){
    // GenricTree<int> *root = new GenricTree<int>(1);
    // GenricTree<int> *n1 = new GenricTree<int>(2);
    // GenricTree<int> *n2 = new GenricTree<int>(3);


    // root -> child.push_back(n1);
    // root -> child.push_back(n2);

    GenricTree<int> *root = takeInput();
    printTree(root);
    return 0;
}