#include <iostream>
#include <vector>

using namespace std;

vector <int> LSP(string &pattern){
    int m = pattern.length();
    vector<int> lsp(m,0);
    int i = 1;
    int j = 0;

    while(i<m){
        if(pattern[i]==pattern[j]){
            j++;
            lsp[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = lsp[j-1];
            }else{
                lsp[j] = 0;
                i++;
            }
        }
    }
    return lsp;
}

vector<int> KMP(string &text, string &pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int> lsp = LSP(pattern);
    vector<int> index;
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
            if(j!=0) j = lsp[j-1];
            else i++;
        }
    }
    return index;
}

int main(){
    string text,pattern;
    cin>>text>>pattern;
    vector<int> res = KMP(text, pattern);
    cout<<res.size()<<endl;
    for(int el : res){
        cout<<el+1<<" ";
    }}