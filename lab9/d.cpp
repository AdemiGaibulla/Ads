#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

vector<int> LSP(string &pattern){
    int m = pattern.length();
    vector<int> lsp(m,0);
    int i = 1, j = 0;

    while(i<m){
        if(pattern[i]==pattern[j]){
            j++;
            lsp[i] = j;
            i++;
        }
        else{
            if(j!=0) j = lsp[j-1];
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
    s[0] = tolower(s[0]);

    int n;
    cin>>n;

    int maxlen = -1;
    vector<string> res;

    for(int i=0; i<n; i++){
        string city;
        cin>>city;

        city[0] = tolower(city[0]);
        string a = city + "#" + s;
        vector<int> lsp = LSP(a);

        if(lsp.back() > maxlen){
            maxlen = lsp.back();
            res.clear();
            res.push_back(city);
        }
        else if(lsp.back() == maxlen && lsp.back()>0) res.push_back(city);
    }

    if(maxlen == 0) cout<<0;
    else{
        cout<<res.size()<<endl;
        for(int i=0; i<res.size(); i++){
            res[i][0] = toupper(res[i][0]);
            cout<<res[i]<<endl;
        }
    }
}