/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL)
        return ;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderval;
    inorder(root,inorderval);
    int n = inorderval.size();
    
    TreeNode<int>* newRoot = new TreeNode<int>(inorderval[0]);
    TreeNode<int>* curr = newRoot;
    
    for(int i=1;i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(inorderval[i]);
        
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}
