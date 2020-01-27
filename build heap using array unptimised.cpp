#include<iostream>
#include <vector>
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

void buildHeap(int *a,int n,vector<int>&heap){
	if(heap.size()==0){
		heap.push_back(a[0]);
	}
	for(int i=1;i<n;i++){
		heap.push_back(a[i]);
		upheapify(heap,heap.size()-1);
	}
}

void display(vector<int>heap){
	for(int i=0;i<heap.size();i++){
		cout << heap[i] << " ";
	}
	cout << endl;
}

int main(){

	vector<int>heap;
	int n;
	cin>>n;

	int a[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	buildHeap(a,n,heap);
	display(heap);
}