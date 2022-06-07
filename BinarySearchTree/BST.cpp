#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBst(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d>root->data){
        root->right = insertIntoBst(root->right,d);
    }
    else{
        root->left = insertIntoBst(root->left,d);
    }
    return root;
}

void inorderdisplay(Node* root)
{
    if(root==NULL)
    {
        return ;
    }

    inorderdisplay(root->left);
    cout<<root->data<<" ";
    inorderdisplay(root->right);
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
         insertIntoBst(root,data);
         cin>>data;
    }
}

Node* minval(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxval(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main() {
    Node* root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    takeInput(root);
      cout<<"Printing the BST: "<<endl;
    inorderdisplay(root);
    cout<<"Minimum value:"<<minval(root)->data<<endl;
    
    return 0;
}
