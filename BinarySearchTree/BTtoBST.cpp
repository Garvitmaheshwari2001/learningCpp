/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
void inorder(BinaryTreeNode<int>* root ,vector<int> &in){
    if(root == NULL)
        return ;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
BinaryTreeNode<int>* buildTree(BinaryTreeNode<int>* root, vector<int> &invalue,int &i){
    if(root == NULL)
        return NULL;
    buildTree(root->left,invalue,i);
    root->data = invalue[i++];
    buildTree(root->right,invalue,i);
}
BinaryTreeNode<int>* binaryTreeToBst(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return NULL;
   vector <int> invalue;
    inorder(root,invalue);
    sort(invalue.begin(),invalue.end());
    int i =0;
        buildTree(root,invalue,i);
    return root;
    }
    

