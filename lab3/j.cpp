#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T(vector<int> bags, int mid){
    int total = 0;
    for(int gold : bags){
        total += (gold + mid - 1) / mid;
    }
    return total;
}

int BinarySearch(int n,vector<int> bags, int h){
    int left = 1;
    int right = *max_element(bags.begin(), bags.end());
    while(left<right){
        int mid = left + (right - left)/2;
        int t = T(bags, mid);
        if(t <= h) right = mid;
        else left = mid+1;
    }
    return left;
}
int main(){
    int n,h;
    cin>>n>>h;
    vector<int> bags(n);
    for(int i=0;i<n;i++) {
        cin>>bags[i];
    }
    cout<<BinarySearch(n, bags, h);


}