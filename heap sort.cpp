#include<iostream>
#include<vector>
using namespace std;

void downheapify(vector<int>&heap,int idx,int size){
    int rightidx=2*idx+2;
    int leftidx=2*idx+1;

    if(rightidx>=size && leftidx>=size){
        return;
    }
    int largestidx=idx;
    if(rightidx<size && heap[rightidx]>heap[largestidx]){
        largestidx=rightidx;
    }
    if(leftidx<size && heap[leftidx]>heap[largestidx]){
        largestidx=leftidx;
    }
    if(largestidx==idx){
        return;
    }
    swap(heap[largestidx],heap[idx]);
    downheapify(heap,largestidx,size);
}

void upheapify(vector<int>&heap,int idx){
    if(idx==0){
        return;
    }
    int parentidx=(idx-1)/2;
    if(heap[parentidx]<heap[idx]){
        swap(heap[idx],heap[parentidx]);
        upheapify(heap,parentidx);
    }
}

void insertInHeap(vector<int>&heap){
    for(int i=0;i<heap.size();i++){
        upheapify(heap,i);
    }
}
void display(vector<int>heap){
    for(int i=0;i<heap.size();i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heapSort(vector<int>&heap,int size){
    if(size==1){
        return;
    }
    swap(heap[0],heap[size-1]);
    size--;
    downheapify(heap,0,size);
    heapSort(heap,size);
}

int main(){
    int n;
    cin>>n;

    vector<int>heap;

    int a[100005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        heap.push_back(a[i]);
    }
    insertInHeap(heap);
    display(heap);
    heapSort(heap,heap.size());
    display(heap);
}