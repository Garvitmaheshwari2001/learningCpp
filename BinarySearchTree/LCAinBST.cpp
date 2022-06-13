/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{  
    /*o(n) o(n)
    if(root == NULL){
        return NULL;
    }
	if(root->data<P->data && root->data<Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    if(root->data>P->data && root->data> Q->data){
      return  LCAinaBST(root->left,P,Q);
    }
   return root;*/
    //o(n) o(1)
    while(root!=NULL){
        if(root->data<P->data && root->data<Q->data)
        root = root->right;
    
    else if(root->data>P->data && root->data> Q->data)
       root = root->left;
    else
    {
        return root;
    }
}
}