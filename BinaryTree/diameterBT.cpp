/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
/*pair<int, int> helper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    pair<int, int> leftans = helper(root->left);
    pair<int, int> rightans = helper(root->right);
    int leftheight = leftans.first;
    int leftdiameter = leftans.second;
    int rightheight = rightans.first;
    int rightdiameter = rightans.second;
    int height = max(leftheight, rightheight) + 1;
    int diameter = max(max(leftdiameter, rightdiameter), leftheight + rightheight);
    pair<int, int> finalans;
    finalans.first = height;
    finalans.second = diameter;
    return finalans;
}
int diameterOfBinaryTree(TreeNode<int> *root)

    pair<int,int> ans=helper(root);
    return ans.second;
}*/
int d(TreeNode<int>* root, int &maxm){
    if(!root) return 0;
    int lh = d(root->left, maxm);
    int rh = d(root->right, maxm);
    maxm = max(maxm,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
        int maxm = 0;
    d(root,maxm);
    return maxm;
}
