#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void upheapify(vector<int>&heap,int idx){
    if(idx==0){
        return;
    }
    int parentidx=(idx-1)/2;
    if(heap[parentidx]<heap[idx]){
        int temp=heap[parentidx];
        heap[parentidx]=heap[idx];
        heap[idx]=temp;
        upheapify(heap,parentidx);
    }
}

void insertInHeap(vector<int>&heap,int x){
    heap.push_back(x);
    upheapify(heap,heap.size()-1);
}

void display(vector<int>&heap){
    for(int i=0;i<heap.size();i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

void downheapify(vector<int>&heap,int idx){
    int rightidx=2*idx+2;
    int leftidx=2*idx+1;

    if(rightidx>=heap.size() && leftidx>=heap.size()){
        return;
    }
    int largestidx=idx;
    if(rightidx<heap.size() && heap[largestidx]<heap[rightidx]){
        largestidx=rightidx;
    }
    if(leftidx<heap.size() && heap[largestidx]<heap[leftidx]){
        largestidx=leftidx;
    }
    if(largestidx==idx){
        return;
    }
    swap(heap[idx],heap[largestidx]);
    downheapify(heap,largestidx);
}
void deleteAnyNode(vector<int>&heap,int i){
    heap[i]=INT_MAX;
    upheapify(heap,i);
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downheapify(heap,0);
}

int main(){
    int n;
    cin>>n;

    vector<int>heap;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertInHeap(heap,x);
    }
    display(heap);
    deleteAnyNode(heap,1);
    display(heap);
}