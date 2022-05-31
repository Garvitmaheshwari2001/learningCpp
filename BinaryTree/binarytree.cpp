#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

node* buildtree(node* root){
         cout<<"enter the data: "<<endl;
         int data;
         cin>>data;
         root = new node(data);

         if(data == -1){
             return NULL;
         }
         cout<<"enter data for inserting in left of "<< data << endl;
         root->left = buildtree(root->left);
         cout<<"enter data for inserting in right of "<< data << endl;
         root->right = buildtree(root->right);
         return root;
}


void levelOrderTransversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
        //level is empty
        cout<<endl;
        if(!q.empty()){
            //q still has some child node
            q.push(NULL);
        }
    }
    else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//same for preorder NLR
// same for postorder LRN

void buildfromLevelOrder(node* &root){
    queue<node*> q;
    
    cout<<"enter data for root: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
          cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
        }
}

int main() {
    node* root = NULL;
    //creating a node
    root = buildtree(root);
    buildfromLevelOrder(root);
    levelOrderTransversal(root);
    
    cout<<"inorder transversal is: ";
    inorder(root);
    return 0;
}
