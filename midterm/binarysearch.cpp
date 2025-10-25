#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int>& v, int target, int n){
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(v[mid]==target) {
            ans = mid;
            break;
        }
        else if(v[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int target;
    cin>>target;
    int ans = BinarySearch(v, target, n);
}