#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> LSP(string &pattern){
    int m = pattern.length();
    vector<int> lsp(m, 0);
    int i = 1, j = 0;

    while(i<m){
        if(pattern[i] == pattern[j]){
            j++;
            lsp[i] = j;
            i++;
        }
        else{
            if(j != 0){
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

int main(){
    string s;
    cin>>s;
    vector<int> lsp = LSP(s);
    cout<<lsp.size()-lsp.back();
}