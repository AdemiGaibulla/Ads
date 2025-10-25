//date sort
#include <iostream>
#include <vector>

using namespace std;

bool lesstrp(const vector<int>& t1, const vector<int>& t2){
    if(t1[2]!=t2[2]) return t1[2] < t2[2];
    if(t1[1]!=t2[1]) return t1[1] < t2[1];
    else return t1[0] < t2[0];
}

int partition(vector<vector<int>>& v, int low, int high){
    vector<int> pivot = v[high];
    int i = low -1;
    for(int j=low;j<high;j++){
        if(lesstrp(v[j],pivot)){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return i+1;
}

void quickSort(vector<vector<int>>& v, int low, int high){
    if(low<high){
        int pi = partition(v,low,high);
        quickSort(v, low, pi-1);
        quickSort(v, pi+1, high);
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int day = stoi(s.substr(0,2));
        int month = stoi(s.substr(3,2));
        int year = stoi(s.substr(6,4));
        v.push_back({day, month, year});
    }

    quickSort(v, 0, n-1);
    for(int i=0;i<n;i++){
        int count1 = 0;
        int temp1 = v[i][0];
        while(temp1 > 0){
            temp1 /= 10;
            count1++;
        }
        int count2 = 0;
        int temp2 = v[i][1];
        while(temp2 > 0){
            temp2 /= 10;
            count2++;
        }
        if(count1==1 && count2==1) cout<<0<<v[i][0]<<"-"<<0<<v[i][1]<<"-"<<v[i][2]<<endl;
        else if(count1==1) cout<<0<<v[i][0]<<"-"<<v[i][1]<<"-"<<v[i][2]<<endl;
        else if(count2==1) cout<<v[i][0]<<"-"<<0<<v[i][1]<<"-"<<v[i][2]<<endl;
        else cout<<v[i][0]<<"-"<<v[i][1]<<"-"<<v[i][2]<<endl;
    }
}