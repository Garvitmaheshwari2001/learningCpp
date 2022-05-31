/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

/*vector<int> reverseLevelOrder(TreeNode<int> *root){
   queue<TreeNode<int>*> q;
   vector<int> ans;
   if(root==NULL) return ans;
   q.push(root);
   while(!q.empty()){
       TreeNode<int>* front=q.front();
       q.pop();
       ans.push_back(front->val);
       if(front->left!=NULL) q.push(front->left);
       if(front->right!=NULL) q.push(front->right);
   }
   reverse(ans.begin(),ans.end());
   return ans;
}*/
vector<int> reverseLevelOrder(TreeNode<int> *root){
    queue<TreeNode<int>*> q;
    stack<int> s;
    vector<int> ans;
    //base case
    if(root == NULL)
        return ans;
       q.push(root);
    while(!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        s.push(front->val);
         if(front->left) q.push(front->left);
       if(front->right) q.push(front->right);
    }
    while(!s.empty()){
        int front = s.top();
        s.pop();
        ans.push_back(front);
    }
    return ans;
}
