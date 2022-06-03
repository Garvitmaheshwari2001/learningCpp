/**********************************************************

    Following is the Binary Tree Node class structure

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
BinaryTreeNode<int> * util(vector<int> & parent,int k,unordered_map<int,queue<int>> &has)
{
    int index = -1;
    if(!has[k].empty()){
        index = has[k].front();
        has[k].pop();
    }

    if(index == -1)
        return NULL;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(index);
    root -> left = util(parent,index,has);
    root ->right = util(parent,index,has);
    return root;
}
BinaryTreeNode<int>* createTree(vector<int> &parent)
{
    if(parent.size()  == 0)
        return NULL;
    unordered_map<int,queue<int>> has;
    for(int i = 0 ; i < parent.size();i++)
    {
        has[parent[i]].push(i);
    }
    return util(parent,-1,has);
}