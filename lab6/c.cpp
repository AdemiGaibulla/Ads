//least absolute difference
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int left, int mid, int right){
    int n1 = mid - left +1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);

    for(int i=0;i<n1;i++) L[i] = v[left+i];
    for(int i=0;i<n2;i++) R[i] = v[mid+1+i];

    int i=0, j=0, k=left;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            v[k] = L[i];
            i++;
        }
        else{
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        v[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& v, int left, int right){
    if(left<right){
        int mid = left + (right - left)/2;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    mergeSort(v, 0, n-1);

    int mindistance = v[1] - v[0];
    for(int i=0;i<n-1;i++){
        int dif = v[i+1] - v[i];
        if(dif < mindistance) mindistance = dif;
    }
    for(int i=0;i<n-1;i++){
        int dif = v[i+1] - v[i];
        if(mindistance == dif) cout<<v[i]<<" "<<v[i+1]<<" ";
    }
}