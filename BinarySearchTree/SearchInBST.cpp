/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int>* temp = root;
    
    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        if(temp->data>x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}