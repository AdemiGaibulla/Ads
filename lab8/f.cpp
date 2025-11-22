#include <iostream>
#include <unordered_set>

using namespace std;

const long long P = 31;

int main(){
    string s;
    cin>>s;
    unordered_set<long long> a;
    for(int i=0; i<s.length(); i++){
        long long hash = 0;
        for(int j=i; j<s.length(); j++){
            hash = hash * P + (s[j] - 'a' + 1);
            a.insert(hash);
        }
    }
    cout<<a.size();
}