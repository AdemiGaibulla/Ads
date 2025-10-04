#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0; i<n; i++){
        string student;
        cin>>student;
        v.push_back(student);
    }
    vector<string>::iterator it= unique(v.begin(), v.end());
    v.erase(it,v.end());

    cout<<"All in all: "<<v.size()<<endl;
    cout<<"Students:"<<endl;
    for(int i=v.size()-1; i>=0;i--){
        cout<<v[i]<<endl;
    }
}