/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
#include<bits/stdc++.h>
void is(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node,BinaryTreeNode<int>* &next ,  BinaryTreeNode<int>* &temp){
  if(root == NULL)
        return;
 
    is(root->right, node, next,temp);
     
    // if target node found then enter this condition
    if(root->data == node->data)
    {
        temp= next;
        // this will be true to the last node
        // in inorder traversal i.e., rightmost node.
        if(root->right == NULL)
             return ;
    }
    next = root;
    is(root->left,node, next,temp);
    return;
}
BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    if(root == NULL)
        return NULL;
    BinaryTreeNode<int> *next = NULL;
        BinaryTreeNode<int> *temp = NULL;
     is(root,node,next,temp);
    return temp;
}