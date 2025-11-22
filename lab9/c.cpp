#include <iostream>
#include <vector>

using namespace std;

vector<int> LSP(string &pattern){
    int m = pattern.length();
    vector<int> lsp(m,0);
    int i = 1, j = 0;

    while(i<m){
        if(pattern[i] == pattern[j]){
            j++;
            lsp[i] = j;
            i++;
        }
        else{
            if( j != 0){
                j = lsp[j-1];
            }
            else{
                lsp[i] = 0;
                i++;
            }
        }
    }
    return lsp;
}

vector<int> KMP(string &pattern, string &text){
    int n = text.length();
    int m = pattern.length();
    vector<int> lsp = LSP(pattern);
    vector<int> index;
    int i = 0, j = 0;

    while(i<n){
        if(pattern[j] = text[i]){
            i++;
            j++;
        }
        if(j==m){
            index.push_back(i-j);
            j = lsp[j-1];
        }
        else if(i<n && pattern[j] != text[i]){
            if(j != 0) j = lsp[j-1];
            else i++;
        }
    }
    return index;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    s2 += s2;
    vector<int> res = KMP(s1, s2);
    if(res.empty()) cout<<-1;
    else cout<<res[0];
}