/************************************************************

    Following is the Tree node structure:
    
    template <typename T>
    class TreeNode 
    {
        public : 
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int>* root,int len,int &maxlen,int &sum){
     if(root == NULL)
         return ;
    if(root->left == NULL && root->right == NULL){
        if(len == maxlen){
            sum += root->data;
        }else if(len>maxlen){
            sum = root->data;
            maxlen = len;
        }return ;
    }
    solve(root->left,len+1,maxlen,sum);
    solve(root->right,len+1,maxlen,sum);
    
    return ;
}
int deepestLeavesSum(TreeNode<int>* root)
{
    int len= 0;
    int maxlen = 0;
    int sum = 0;
  
    
    solve(root,len,maxlen,sum);
    return sum;
}