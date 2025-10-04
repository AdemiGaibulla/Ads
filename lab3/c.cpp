#include <iostream>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr[i]=element;
    }

    for(int i=0; i<q; i++){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int cnt=0;
        for(int j=0; j<n; j++){
            if(l1<=arr[j] && arr[j]<=r1 || l2<=arr[j] && arr[j]<=r2){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}