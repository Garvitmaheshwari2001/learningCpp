/**********************************************************
    Following is the Binary Tree Node class structure.

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
//You are given two Binary Trees. You need to return true if the diagonals of trees are anagram to each other, otherwise you need to return false.
#include<bits/stdc++.h>
bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    queue<BinaryTreeNode<int>*> q1,q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() && !q2.empty()){
        int size1 = q1.size();
        int size2 = q2.size();
        if(size1 != size2)
            return false;
        while(size1--){
            BinaryTreeNode<int>* node1 = q1.front();
            BinaryTreeNode<int>* node2 = q2.front();
            q1.pop();q2.pop();
            vector<int> v1,v2;
            while(node1){
                v1.push_back(node1->data);
                if(node1->left){
                    q1.push(node1->left);
                }
                node1 = node1->right;
            }
            while(node2){
                v2.push_back(node2->data);
                if(node2->left){
                    q2.push(node2->left);
                } 
                node2 = node2->right;
            }
            sort(v1.begin(),v1.end());
             sort(v2.begin(),v2.end());
            if(v1 != v2)
                return false;
        }
    }
    return true;
}
