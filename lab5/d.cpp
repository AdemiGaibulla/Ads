#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    priority_queue<long long, vector<long long>, greater <long long>> minHeap;
    for(long long i=0; i<n; i++){
        long long d;
        cin>>d;
        minHeap.push(d);
    }

    long long cnt=0;

    while(true){
        if(minHeap.size()==0) break;
        if(minHeap.top()>=m) minHeap.pop();
        else{
            int x = minHeap.top();
            minHeap.pop();
            int y = minHeap.top();
            minHeap.pop();
            minHeap.push(x*2+y);
            cnt++;
        }
        if(minHeap.size()==1 && minHeap.top()<m) {
            cnt = -1;
            break;
        }
    }
    cout<<cnt;
}