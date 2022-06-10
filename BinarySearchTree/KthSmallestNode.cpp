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
int solve(TreeNode<int>* root,int &i,int k){
    //base case
    if(root == NULL)
        return -1;
    
    int left = solve(root->left,i,k);
    if(left != -1){
        return left;
    }
    i++;
    if(i == k){
        return root->data;
    }
    return solve(root->right,i,k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int i = 0;
	int ans = solve(root,i,k);
    return ans;
}