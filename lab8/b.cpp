#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> LSP(const string &pattern){
    int m = pattern.length();
    vector<int> lsp(m,0);
    int j = 0;
    int i = 1;

    while(i < m){
        if(pattern[i] == pattern[j]){
            j++;
            lsp[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j  = lsp[j-1];
            }else{
                lsp[i] = 0;
                i++;
            }
        }
    }
    return lsp;
}

vector<int> KMP(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int> lsp = LSP(pattern);
    int i = 0, j = 0;
    vector<int> index;

    while(i < n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j == m){
            index.push_back(i-j);
            j = lsp[j-1];
        }else if(i < n && pattern[j] != text[i]){
            if(j != 0) j = lsp[j-1];
            else i++;
        }
    }
    return index;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    string parasite;
    cin>>parasite;

    vector<int> pos1 = KMP(s1,parasite);
    vector<int> pos2 = KMP(s2, parasite);
    int count = 0;

    sort(pos2.begin(), pos2.end());

    for (int x : pos1) {
        if (binary_search(pos2.begin(), pos2.end(), x)) {
            count++;
        }
    }

    cout<<count;
}