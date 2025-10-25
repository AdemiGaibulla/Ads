//common numbers
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& v, int low, int high){
    int pivot = v[high];
    int i = low -1;

    for(int j=low;j<high;j++){
        if(v[j]<=pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return i+1;
}

void quickSort(vector<int>& v, int low, int high){
    if(low<high){
        int pi = partition(v,low,high);
        quickSort(v, low, pi-1);
        quickSort(v, pi+1, high);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> first(n);
    vector<int> second(m);
    for(int i=0;i<n;i++) cin>>first[i];
    for(int i=0;i<m;i++) cin>>second[i];

    quickSort(first, 0, n-1);
    quickSort(second, 0, m-1);
    int i=0,j=0;
    while(i<n && j<m){
        if(first[i]==second[j]) {
            cout<<first[i]<<" ";
            i++;
            j++;
        }
        else if(first[i]<second[j]) i++;
        else j++;
    }
}