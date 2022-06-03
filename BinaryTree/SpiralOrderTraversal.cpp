/************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
************************************************************/
#include <bits/stdc++.h>

vector<int> spiralOrder(BinaryTreeNode<int> *root)
{
    // Write Your Code Here.
    vector<int> ans;
    if(root == NULL) return ans;
    stack<BinaryTreeNode<int>*> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            BinaryTreeNode<int> *temp = s1.top();
            ans.push_back(temp->data);
            s1.pop();
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        while(!s2.empty())
        {
            BinaryTreeNode<int> *temp = s2.top();
            ans.push_back(temp->data);
            s2.pop();
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
    }
    return ans;
}