#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    map<int, int> mp;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        mp[number]++;
    }
    int maxf=0;
    for(map<int,int>:: iterator it=mp.begin(); it!=mp.end(); it++){
        if(maxf < it->second) maxf = it->second;
    }
    for (map<int,int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); ++it) {
    if(it->second==maxf) cout<<it->first<<" ";
}

}