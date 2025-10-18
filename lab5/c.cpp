#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<long long> maxHeap;
    long long n, x;
    cin>>n>>x;
    for(long long i=0; i<n; i++){
        long long k;
        cin>>k;
        maxHeap.push(k);
    }
    long long sum=0;
    while(x!=0){
        int element = maxHeap.top();
        maxHeap.pop();
        sum+=element;
        maxHeap.push(element-1);
        x--;
    }
    cout<<sum;
}