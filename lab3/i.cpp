#include <iostream>

using namespace std;

bool BinarySearch(int arr[], int n, int target){
    int left = 0;
    int right = n-1;
    if(target == arr[0] || target == arr[n-1]) return true;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(target == arr[mid]) return true;
        else if(target < arr[mid]) right = mid-1;
        else left = mid + 1;
    }
    return false;

}
int main(){
    int n,target;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr[i]=element;
    }
    cin>>target;
    if(BinarySearch(arr, n, target)) cout << "Yes";
    else cout<<"No";
}