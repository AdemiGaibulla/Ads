#include <iostream>
#include <vector>

using namespace std;

vector<int> LSP(string &pattern){
    int m = pattern.length();
    vector<int> lsp(m, 0);
    int j = 0;
    int i = 1;

    while(i<m){
        if(pattern[i] == pattern [j]){
            j++;
            lsp[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = lsp[j-1];
            }else{
                lsp[i] = 0;
                i++;
            }
        }
    }
    return lsp;
}

int KMP(string &text, string &pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int> lsp = LSP(pattern);
    int i = 0, j = 0;

    int count = 0;

    while(i<n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j==m){
            count++;
            j = lsp[j-1];
        }
        else if(i<n && pattern[j]!=text[i]){
            if(j!=0) j = lsp[j-1];
            else i++;
        }
    }
    return count;
}

int main(){
    string word, password;
    int n;
    cin>>word>>n>>password;
    int cnt = KMP(password,word);
    if(cnt >= n) cout<<"YES";
    else cout<<"NO";
}