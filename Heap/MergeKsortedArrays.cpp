#include<bits/stdc++.h>

/*class node{
    public:
    int data;
    int r;
    int c;
    
    node(int data,int row,int col){
        this->data = data;
        r =row;
        c= col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
     priority_queue<node* ,vector<node*>,compare>p;
    vector<int> ans;
    
    for(int i =0;i<k;i++){
        node* temp = new node(kArrays[i][0],i,0);
        p.push(temp);
    }
    while(p.size()>0){
        node* top = p.top();
        ans.push_back(top->data);
        p.pop();
        
        int i = top->r;
        int j = top->c;
        if(j+1 <kArrays[i].size()){
            node * next = new node(kArrays[i][j+1],i,j+1);
            p.push(next);
        }
    }
    return ans;
}*/

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
     priority_queue<int,vector<int>,greater<int>>pq;
    vector<int> ans;
    for(auto i:kArrays){
        for(auto j:i){
            pq.push(j);
        }
    }
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}