#include <iostream>
#include <vector>

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
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        int number;
        cin>>s>>number;
        int m = s.size();

        vector<int> lsp = LSP(s);
        int a = lsp.size() - lsp.back();

        cout<< m + (number - 1) * a<<endl;
    }
}