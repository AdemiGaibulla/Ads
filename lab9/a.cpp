#include <iostream>
#include <vector>

using namespace std;

vector<long long> LSP(string &pattern){
    int m = pattern.length();
    vector<long long> lsp(m, 0);
    int i = 1, j = 0;

    while(i < m){
        if(pattern[i] == pattern[j]){
            j++;
            lsp[i] = j;
            i++; 
        }
        else{
            if(j!=0){
                j = lsp[j-1];
            }else{
                lsp[i] = 0;
                i++;
            }
        }
    }
    return lsp;
}

vector<long long> KMP (string &pattern, string &text){
    int n = text.length();
    int m = pattern.length();
    vector<long long> lsp = LSP(pattern);
    vector<long long> index;
    int i = 0, j = 0;

    while(i<n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j==m){
            index.push_back(i-j);
            j = lsp[j-1];
        }
        else if(i<n && text[i] != pattern[j]){
            if(j != 0) j = lsp[j-1];
            else i++;
        }
    }
    return index;
}

int main(){
    string pattern, text;
    cin>>text>>pattern;

    string s = text;
    int count = 1;

    while(pattern.length() > s.size()){
        s += text;
        count++;
    }

    if(!(KMP(pattern, s).empty())) cout<<count;
    else{
        s += text;
        count++;
        if(!(KMP(pattern, s).empty())) cout<<count;
        else cout<<-1;
    }
}