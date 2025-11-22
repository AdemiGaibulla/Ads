#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void merge(vector<string>& v, int left, int mid, int right){
    int n1 = mid - left+1;
    int n2 =  right - mid;

    vector<string> L(n1);
    vector<string> R(n2);

    for(int i=0;i<n1;i++) L[i] = v[left+i];
    for(int i=0;i<n2;i++) R[i] = v[mid+i+1];

    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i].size()<=R[j].size()){
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

void mergeSort(vector<string>& v, int left, int right){
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
    cin.ignore();
    for(int i=0;i<n;i++){
        string line;
        getline(cin,line);
        stringstream ss(line);
        vector<string> v;
        string letters;
        while(ss>>letters){
            v.push_back(letters);
        }
        mergeSort(v, 0, v.size()-1);
        for(int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
}