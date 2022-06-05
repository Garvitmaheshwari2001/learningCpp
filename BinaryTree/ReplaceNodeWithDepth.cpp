
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
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

*************************************************************/
BinaryTreeNode<int> *solve(BinaryTreeNode<int> *root,int depth){
    if(root == NULL){
        return root;
    }
    root->data = depth;
    BinaryTreeNode<int>* leftAns = solve(root->left,depth+1);
     BinaryTreeNode<int>* rightAns = solve(root->right,depth +1);
    root->left = leftAns;
    root->right = rightAns;
    return root;
}
BinaryTreeNode<int> *changeToDepthTree(BinaryTreeNode<int> *root)
{
    if(root == NULL){
        return root;
    }
    int depth =0;
   BinaryTreeNode<int>* ans = solve(root,depth);
    return ans;
}
