/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
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

***********************************************************/

BinaryTreeNode<int>* deepestRightLeaf(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return NULL;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    BinaryTreeNode<int>* result = NULL;
    while(!q.empty()){
         BinaryTreeNode<int>* temp = q.front();
        q.pop();
        
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
            if(!temp->right->left && !temp->right->right)
                result = temp->right;
        }
    }
    return result;
}