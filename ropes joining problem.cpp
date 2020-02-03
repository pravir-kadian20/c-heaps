#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int cost(int *ropes,int n){
    priority_queue<int,vector<int>,greater<int>> pq(ropes,ropes+n);
    int cost=0;
    while(pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        cost+=first+second;
        pq.push(first+second);
    }
    return cost;
}

int main(){
    int n;
    cin>>n;

    int ropes[100005];
    for(int i=0;i<n;i++){
        cin>>ropes[i];
    }
    cout << cost(ropes,n) << endl;
}