/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
priority_queue<int,vector<int>,greater<int> > p;
void pre(BinaryTreeNode* root){
    if(!root)
        return ;
    p.push(root->data);
    pre(root->left);
    pre(root->right);
}
void convert(BinaryTreeNode* root){
   if(!root)
       return ;
    root->data = p.top();
    p.pop();
    convert(root->left);
    convert(root->right);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	pre(root);
    convert(root);
    return root;
}