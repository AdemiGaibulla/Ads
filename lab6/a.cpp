//alphabet sort vowel first 

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<char>& v, int left, int mid, int right){
    int n1 = mid - left+1;
    int n2 = right - mid;
    vector<char> L(n1);
    vector<char> R(n2);


    for(int i=0; i<n1; i++) L[i] = v[left+i];
    for(int i=0; i<n2; i++) R[i] = v[mid+1+i];

    int i=0, j=0, k=left;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
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

void mergeSort(vector<char>& v, int left, int right){
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
    vector<char> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<char> vowels;
    vector<char> consonants;
    for(int i=0;i<n;i++){
        if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u') vowels.push_back(v[i]);
        else consonants.push_back(v[i]);
    }

    if (!vowels.empty()) mergeSort(vowels, 0, vowels.size() - 1);
    if (!consonants.empty()) mergeSort(consonants, 0, consonants.size() - 1);

    for(int i=0;i<vowels.size();i++) cout<<vowels[i];
    for(int i=0;i<consonants.size();i++) cout<<consonants[i];
}