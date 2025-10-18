#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(){
    priority_queue<int> maxHeap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        maxHeap.push(num);
    }
    while(maxHeap.size()>1){
        int x = maxHeap.top();
        maxHeap.pop();
        int y = maxHeap.top();
        maxHeap.pop();
        if(x==y && maxHeap.size()<2) maxHeap.push(0);
        if(x!=y) maxHeap.push(abs(y-x));
    }
    cout<<maxHeap.top();
}
