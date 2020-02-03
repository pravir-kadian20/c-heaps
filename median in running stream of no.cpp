#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void median(int *a,int n){
    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int>>g;

    int ans=a[0];
    s.push(a[0]);
    cout << ans << " ";

    for(int i=1;i<n;i++){
        int x=a[i];

        if(s.size()>g.size()){
            if(x>=ans){
                g.push(x);
            }
            else{
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            ans=(s.top()+g.top())/2;
        }
        else if(s.size()<g.size()){
            if(x>ans){
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else{
                s.push(x);
            }
            ans=(s.top()+g.top())/2;
        }
        else{
            if(x>ans){
                g.push(x);
                ans=g.top();
            }
            else{
                s.push(x);
                ans=s.top();
            }    
        }
        cout << ans << " ";
    }
}

int main(){
    int n;
    cin>>n;

    int a[100005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    median(a,n);
}