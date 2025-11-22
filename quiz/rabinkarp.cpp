#include <iostream>
#include <string>

using namespace std;

const int P = 31;

long long computeHash(const string &s){
    long long hash = 0;
    for(char c : s){
        hash = hash * P + (c - 'a' + 1);
    }
    return hash;
}

void rabinKarp(const string &text, const string &pattern){
    int n = text.size();
    int m = pattern.size();
    if(m>n) return;

    long long hashT = computeHash(text.substr(0,m));
    long long hashP = computeHash(pattern);

    long long pm = 1;
    for(int i=0; i<m-1; i++) pm *= P;

    for(int i=0; i+m <=n; i++){
        if(hashT == hashP){
            bool match = true;
            for(int j=0; j<m; j++){
                if(text[i+j] != pattern[j]){
                    match = false;
                    break;
                }
            }
            if(match) cout<<"Pattern found at index:"<<i<<endl;
        }
        if(i+m<n){
            hashT = (hashT - pm * (text[i] - 'a' + 1)) * P + (text[i+m] - 'a' + 1);
        }
    }
}

int main(){}