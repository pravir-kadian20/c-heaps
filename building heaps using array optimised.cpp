#include<iostream>
#include<vector>
using namespace std;

void upheapify(vector<int>&heap,int idx){
    if(idx==0){
        return;
    }
    int parentidx=(idx-1)/2;
    if(heap[parentidx]<heap[idx]){
        swap(heap[parentidx],heap[idx]);
        upheapify(heap,parentidx);
    }
}

void buildHeap(vector<int>&heap){
    for(int i=heap.size()-1;i>=0;i--){
        upheapify(heap,i);
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
    buildHeap(heap);
    display(heap);
}