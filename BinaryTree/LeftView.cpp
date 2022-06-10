/************************************************************

    Following is the Binary Tree node structure

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
    };

************************************************************/
/*void solve(BinaryTreeNode<int>* root , vector<int> &ans, int level){
    if(root == NULL)
        return ;
        if(level == ans.size())
            ans.push_back(root->data);
    solve(root->left,ans,level+1);
    solve(root->right, ans, level+1);
            
}*/
void printLeftView(BinaryTreeNode<int> *root)
{
   /* vector<int> ans;
    solve(root, ans,0);*/
     if(!root)
        return;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
           BinaryTreeNode<int> *curr=q.front();
            q.pop();
            if(i==1)
                cout<<curr->data<<" ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
}