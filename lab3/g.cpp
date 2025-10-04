#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T(vector<int> v, int mid){
    int total = 0;
    for(int child : v){
        total += (child + mid - 1)/mid;
    }
    return total;
}

int BinarySearch(vector<int> v,int f){
    int left = 1;
    int right = *max_element(v.begin(), v.end());
    while(left<right){
        int mid = left + (right - left)/2;
        int t = T(v, mid);
        if(t<=f) right = mid;
        else left = mid +1;
    }
    return left;
}

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> children(n);
    for (int i = 0; i < n; i++) cin >> children[i];

    cout<<BinarySearch(children, f);
    
}
