/*
    Following is the class structure of BinaryTreeNode class for referance:

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

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
#include<bits/stdc++.h>

/*BinaryTreeNode<int>* solve(vector<int>* &preorder,int min, int max , int &i){
    if(i >= preorder.size()){
        return NULL;
    }
    if(preorder[i] < min || preorder[i] > max){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i+1]);
    root->left = solve(preoder,min,root->data,i);
    root->right = solve(preorder,root->data , max , i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    if(preorder.size() == 0){
        return NULL;
    }
    int min = INT_MIN;
    int max = INT_MAX;
    int i =0;
    return solve(preorder,min,max,i);
}*/
*/#include<bits/stdc++.h>
BinaryTreeNode<int>* helper(vector<int> &preorder,int &i,int max){
    if(i==preorder.size() || preorder[i]>max){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[i]);
    i++;
    BinaryTreeNode<int>* leftchild=helper(preorder,i,root->data);
    BinaryTreeNode<int>* rightchild=helper(preorder,i,max);
    root->left=leftchild;
    root->right=rightchild;
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    if(preorder.size()==0){
        return NULL;
    }
    int max=INT_MAX;
    int i=0;
    BinaryTreeNode<int>* root=helper(preorder,i,max);
    return root;
}*/