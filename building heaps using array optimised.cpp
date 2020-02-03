#include<iostream>
#include<vector>
using namespace std;

void downheapify(vector<int>&heap,int idx){
    int rightidx=2*idx+2;
    int leftidx=2*idx+1;

    if(rightidx>=heap.size() && leftidx>=heap.size()){
        return;
    }
    int largestidx=idx;
    if(rightidx<heap.size() && heap[rightidx]>heap[largestidx]){
        largestidx=rightidx;
    }
    if(leftidx<heap.size() && heap[leftidx]>heap[largestidx]){
        largestidx=leftidx;
    }
    if(largestidx==idx){
        return;
    }
    swap(heap[largestidx],heap[idx]);
    downheapify(heap,largestidx);
}

void insertInHeap(vector<int>&heap){
    for(int i=heap.size()-1;i>=0;i--){
        downheapify(heap,i);
    }
}

void display(vector<int>heap){
    for(int i=0;i<heap.size();i++){
        cout << heap[i] << " ";
    }
    cout << endl;
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
}
