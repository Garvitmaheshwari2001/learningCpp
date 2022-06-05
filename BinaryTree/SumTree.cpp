/*************************************************************
 
    Following is the Binary Tree node structure

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
//For a given binary tree, convert it to its sum tree. That is, replace every node data with sum of its immediate children, keeping leaf nodes 0. Finally, return its preorder.
void st(BinaryTreeNode<int>* root){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        root->data = 0;
    }else if(root->left == NULL && root->right !=NULL){
        root->data = root->right->data;
    }else if(root->left != NULL && root->right == NULL){
        root->data = root->left->data;
    }else{
        root->data = root->left->data + root->right->data;
    }
    st(root->left);
    st(root->right);
}

void preorder(BinaryTreeNode<int>* root, vector<int> &ans){
    if(root == NULL){
        return ;
    }
   ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
vector<int> sumTree(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    //st for sumtree
    st(root);
    preorder(root,ans);
    return ans;
}