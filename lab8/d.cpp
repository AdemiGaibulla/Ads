#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long P = 31;
const long long MOD = 1e9 + 7;

long long ComputeHash(const string &s) {
    long long hash = 0;
    for (int i=0; i<s.length(); i++) {
        hash = hash * P + (s[i] - 'a' + 1);
    }
    return hash;
}

int cnt_of_substr(string &text, string &pattern) {
    int n = text.length();
    int m = pattern.length();
    long long hashT = ComputeHash(text.substr(0, m));
    long long hashP = ComputeHash(pattern);

    long long pm = 1;
    for (int i=0; i<m-1; i++) pm *= P;
    
    int cnt = 0;
    for (int i=0; i+m <= n; i++) {
        if (hashT == hashP) {
            cnt++;
        }
        if (i + m < n)
            hashT = (hashT - pm * (text[i] - 'a' + 1)) * P + (text[i + m] - 'a' + 1);
    }
    return cnt;
}

int main() {
    while (true) {
        int n; 
        cin >> n;
        if (n == 0) break;

        vector<string> v(n);
        vector<string> res;
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        string s; 
        cin >> s;

        int mx = -2;
        int maxcount = 0;
        for(int i=0; i<n; i++) {
            int count = cnt_of_substr(s, v[i]);
            if (count > mx) {
                mx = count;
                maxcount = count;
                res.clear();
                res.push_back(v[i]);
            } else if (count == mx) {
                res.push_back(v[i]);
            }

        }

        cout << maxcount << endl;
        for(auto cur: res) {
            cout << cur << endl;
        }
    }
}