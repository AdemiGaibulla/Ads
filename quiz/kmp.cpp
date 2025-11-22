#include <iostream>
#include <vector>

using namespace std;

vector<int> LPS(string &pattern){
    int m = pattern.size();
    vector<int> lps(m, 0);
    int i = 1, j = 0;

    while(i<m){
        if(pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0) j = lps[j-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string &pattern, string &text){
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = LPS(pattern);
    vector<int> index;
    int i = 0, j = 0;

    while(i<n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            index.push_back(i-j);
            j = lps[j-1];
        }
        else if(i<n && text[i] != pattern[j]){
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return index;
}