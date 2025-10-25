//Azat is a perfectionist and he likes everything to be perfect. Help Azat sort letters alphabetically. good luck!
#include <iostream>

using namespace std;

void merge(string &s, int left, int mid, int right){
    int n1 = mid - left+1;
    int n2 = right - mid;

    string L = s.substr(left, n1);
    string R = s.substr(mid + 1, n2);

    int i=0, j=0, k=left;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            s[k] = L[i];
            i++;
        }
        else{
            s[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        s[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        s[k] = R[j];
        j++;
        k++;
    }
}

void  mergeSort(string &s, int left, int right){
    if(left<right){
        int mid = left + (right - left)/2;
        mergeSort(s, left, mid);
        mergeSort(s, mid+1, right);
        merge(s, left, mid, right);
    }
}

int main(){
    string s;
    cin>>s;
    mergeSort(s, 0, s.length()-1);
    cout<<s;
}