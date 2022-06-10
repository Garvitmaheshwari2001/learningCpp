/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key){
    if(root == NULL){
        return root;
    }
    if(key>root->data){
        root->right = deleteNode(root->right,key);
    }
   else if(key<root->data){
        root->left = deleteNode(root->left,key);
    }
    else {
        if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
     else if(root->left!=NULL && root->right==NULL){
            BinaryTreeNode<int>* leftchild=root->left;
            root->left=NULL;
            delete root;
            root=leftchild;
            return root;
        }
         else if(root->right!=NULL && root->left==NULL){
            BinaryTreeNode<int>* rightchild=root->right;
            root->right=NULL;
            delete root;
            root=rightchild;
            return root;
        }
    else{
        BinaryTreeNode<int>* minnode = root->right;
        while(minnode->left != NULL){
            minnode = minnode->left;
        }
        int mindata = minnode->data;
        root->data = mindata;
        root->right = deleteNode(root->right,mindata);
    }
}
return root;
}