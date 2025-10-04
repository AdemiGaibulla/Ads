#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n, m;
    cin>>n>>m;
    vector<long long> blocks(n);
    long long sum=0;
    vector<long long> mistakes(m);
    for(long long i=0;i<n;i++){
        long long block;
        cin>>block;
        sum+=block;
        blocks[i] = sum;
    }
    for(long long i=0;i<m;i++){
        long long mistake;
        cin>>mistake;
        long long left = 0;
        long long right = n-1;
        long long answer = n-1;
        while(left<=right){
            long long mid = left + (right - left)/2;
            if(blocks[mid]>=mistake){
                answer = mid;
                right = mid -1;
            }
            else{
                left = mid +1;
            }
        }
        cout<<answer+1<<endl;
    }
}