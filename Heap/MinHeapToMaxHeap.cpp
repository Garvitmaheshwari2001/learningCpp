void heapfiy (long *arr, int n, int i){
    
    int largest= i;
    int left= 2*i+1;
    int right= 2*i+2;
    
    if (left < n and arr[largest] < arr[left])
         largest= left;
    if (right < n and arr[right] > arr[largest])
         largest= right;
    
    if (largest != i){
        
        swap (arr[i], arr[largest]);
        heapfiy(arr, n, largest);
    }
}
void minHeapToMaxHeap(long *arr, int n)
{
    //Write your code here
    for (int i=n/2; i>=0; i--)
    heapfiy (arr, n, i);
    
}