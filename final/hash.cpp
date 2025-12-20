#include <iostream>
#include <vector>

using namespace std;

const int p = 31;
const int mod = 1000000007;

int computeHash(const string &s){
    int hash = 0;
    int p_pow = 1;
    for(char c : s){
        hash = (hash + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
    }
    return hash;
}

void rabinKarp(const string &text, const string &pattern){
    int n = text.size();
    int m = pattern.size();

    int patternHash = computeHash(pattern);
    int currentHash = computeHash(text.substr(0,m));

    int p_pow_m = 1;\
    for(int i=0; i<m; i++){
        p_pow_m = (p_pow_m * p) % mod;
    }

    for(int i=0; i <= n-m; i++){
        if(currentHash == patternHash){
            if(text.substr(i,m) == pattern) cout<<"Pattern found at index "<<i;
        }
        if(i < n-m){
            currentHash = (currentHash - (text[i] - 'a' + 1) + mod) & mod;
            currentHash = (currentHash * p + (text[i+m] - 'a' + 1)) % mod;
        }
    }
}