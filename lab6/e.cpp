//column sort
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int left, int mid, int right){
    int n1 = mid - left+1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);

    for(int i=0;i<n1;i++) L[i] = v[left+i];
    for(int i=0;i<n2;i++) R[i] = v[mid+1+i];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(L[i]>=R[j]){
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
        int mid = left + (right-left)/2;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<m;i++){
        vector<int> column(n);
        for(int j=0;j<n;j++){
            column[j] = v[j][i];
        }
        mergeSort(column, 0, n-1);
        for(int j=0;j<n;j++){
            v[j][i] = column[j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}