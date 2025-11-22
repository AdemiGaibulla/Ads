#include <iostream>
#include <string>

using namespace std;

const long long P = 31;
const long long MOD = 1e9 + 9; 

long long ComputeHash(const string &s){
    long long hash = 0;
    for( int i=0; i<s.length(); i++){
        hash = hash * P + (s[i] - 'a' + 1);
    }
    return hash;
}

int cnt_of_substr(string &text, string &pattern){
    int n = text.length();
    int m = pattern.length();
    int cnt = 0;
    
    long long hashT = 0;
    for(int i = 0; i < m; i++) hashT = (hashT * P + (text[i] - 'a' + 1));

    long long hashP = ComputeHash(pattern);

    long long pm = 1;
    for(int i=0; i<m-1; i++) pm *= P;

    for(int i=0; i+m<=n; i++){
        if(hashT == hashP) cnt++;
        if(i+m < n){
            hashT = ((hashT - pm * (text[i] - 'a' + 1)) * P + (text[i + m] - 'a' + 1));
        }
    }
    return cnt;
}

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int l,r;
        cin>>l>>r;
        string substring = "";
        for(int j=l-1; j<=r-1; j++){
            substring += s[j];
        }
        cout<<cnt_of_substr(s,substring)<<endl;
    }
}