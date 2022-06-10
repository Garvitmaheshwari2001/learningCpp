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
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    queue<pair<TreeNode<int>*, int>> q;
    map<int,int> topNode;
    q.push({root,0});
    
    while(!q.empty()){
          pair<TreeNode<int>*, int> temp = q.front();
            q.pop();
            TreeNode<int>* frontNode = temp.first;
            int hd = temp.second;
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode->val;
            if(frontNode->left)
                q.push({frontNode->left,hd-1});
            if(frontNode->right)
                q.push({frontNode->right,hd+1});
    }
           for(auto i:topNode) 
        {
            ans.push_back(i.second);
        }
        return ans;
    
}