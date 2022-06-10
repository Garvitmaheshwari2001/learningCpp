/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
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

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
bool solve(BinaryTreeNode<int>*root,int max,int min){
    if(root==NULL){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }
    bool ans1=solve(root->left,root->data-1,min);
    bool ans2=solve(root->right,max,root->data);
    if(ans1==false || ans2==false){
        return false;
    }
    return true;
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    // Write your code here
    if(root==NULL){
        return true;
    }
    bool ans=solve(root,INT_MAX,INT_MIN);
    return ans;
}