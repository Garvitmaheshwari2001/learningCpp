int kthLargest(vector<int>& arr, int size, int K)
{
	    priority_queue<int,vector<int>,greater<int>> pq;
    int cnt =1;
    for(int i=0;i<size;i++){
        pq.push(arr[i]);
        if(cnt>K) pq.pop();
        cnt++;
    }
//     cout<<pq.size();
    return pq.top();
}