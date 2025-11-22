#include <iostream>
#include <vector>

using namespace std;

vector<long long> LSP(string &pattern){
    int m = pattern.length();
    vector<long long> lsp(m,0);
    int i = 1, j = 0;

    while(i<m){
        if(pattern[i] == pattern[j]){
            j++;
            lsp[i] = j;
            i++;
        }
        else{
            if(j!=0){
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

bool check(string &pattern,string &text) {
    if (text.length() < pattern.length()) return false;
    for (int i=0; i<pattern.length(); i++) {
        if (pattern[i] != text[i]) return false;
    }
    return true;
}

bool KMP(string &pattern, string &text){
    int n = text.length();
    int m = pattern.length();
    vector<long long> lsp = LSP(pattern);
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = lsp[j-1];
        } else {
            i++;
        }
    }

    if (j == m && i - j == 0) return true;

    return check(pattern, text);
}

int main(){
    string s;
    cin >> s;

    int n = s.length();
    if(n < 3){
        cout << 0;
        return 0;
    }

    long long cnt = 0;
    for(int i = 1; i * 2 < n; i++){
        string a = s.substr(0, i);
        string text = s.substr(i);
        if (KMP(a, text)) cnt++;
    }
    cout << cnt;
}