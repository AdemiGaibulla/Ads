#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cmath> 

using namespace std;

void shuffle(vector<long long>& v,long long left, long long right){
    if (right <= left) return;
    long long mid = left+(right-left)/2;
    cout<<v[mid]<<" ";
    shuffle(v, mid + 1, right);
    shuffle(v, left, mid);
}
int main(){
    long long h,n;
    cin>>h;
    n = pow(2,h)-1;
    vector<long long> v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    long long left = 0;
    long long right = n;
    shuffle(v, left, right);
}