#include <iostream>

using namespace std;

void merge(int c[], int left, int mid, int right){
    int n1 = mid - left+1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    for(int i=0;i<n1;i++) L[i] = c[left+i];
    for(int i=0;i<n2;i++) R[i] = c[mid+i+1];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            c[k] = L[i];
            i++;
        }
        else{
            c[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        c[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        c[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int c[], int left, int right){
    if(left<right){
        int mid = left + (right - left)/2;
        mergeSort(c, left, mid);
        mergeSort(c, mid+1, right);
        merge(c, left, mid, right);
    }
}
int main(){
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i]; 
    }
    cin>>m;
    int b[m+n];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++) b[m+i] = a[i];
    mergeSort(b, 0, n+m-1);
    for(int i=0;i<n+m;i++){
        cout<<b[i]<<" ";
    }
}