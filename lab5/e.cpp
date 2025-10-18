#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
    long long q,k;
    cin>>q>>k;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    long long sum=0;
    for(long long i=0;i<q;i++){
        string command;
        cin>>command;
        if(command=="print") cout<<sum<<endl;
        else if(command=="insert"){
            long long n;
            cin>>n;
            if(minHeap.size()<k){
                minHeap.push(n);
                sum+=n;
            }
            else if(n>minHeap.top()){
                long long element = minHeap.top();
                minHeap.pop();
                sum-=element;
                minHeap.push(n);
                sum+=n;
            }
        }
    }
}