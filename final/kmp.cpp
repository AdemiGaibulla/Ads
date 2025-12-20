#include <iostream>
#include <vector>
using namespace std;

vector<long long> LPS(string &pattern){
    int m = pattern.length();
    vector<long long> lps(m,0);

    int i = 1, j = 0;

    while(i < m){
        if(pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<long long> KMP (string &pattern, string &text){
    int n = text.length();
    int m = pattern.length();
    vector<long long> lps = LPS(pattern);
    vector<long long> index;
    int i = 0, j = 0;

    while(i<n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j==m){
            index.push_back(i-j);
            j = lps[j-1];
        }
        else if( i<n && text[i] != pattern[j]){
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return index;
}