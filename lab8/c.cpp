#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int P = 31;

int computeHash(const string &s){
    int hash = 0;
    for(char c : s){
        hash = hash * P + (c - 'a' + 1);
    }
    return hash;
}

void issubstr(const string &text, const string &pattern, vector<bool> &v){
    int n = text.length();
    int m = pattern.length();

    int hashP = computeHash(pattern);
    int hashT = computeHash(text.substr(0, m));

    int pm = 1;
    for(int i=0; i<m-1; i++) pm *= P;

    for(int i=0; i + m <= n; i++){
        if(hashT == hashP){
            for(int j = i; j < i + m; j++) v[j] = true;
        }
        if(i + m < n)
            hashT = (hashT - pm * (text[i] - 'a' + 1)) * P + (text[i + m] - 'a' + 1);
    }
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<bool> check(s.size(), false);

    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        issubstr(s, word, check);
    }

    for(int i=0; i<s.size(); i++){
        if(!check[i]){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
