#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

int main(){
    long long n;
    cin>>n;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for(int i=0;i<n;i++){\
        long long number;
        cin>>number;
        minHeap.push(number);
    }
    long long sum = 0;
    long long total = 0;
    while(minHeap.size()>1){
        long long minelement1 = minHeap.top();
        minHeap.pop();
        long long minelement2 = minHeap.top();
        minHeap.pop();
        sum = minelement1+ minelement2;
        total += sum;
        minHeap.push(sum);
    }
    cout<<total;
}