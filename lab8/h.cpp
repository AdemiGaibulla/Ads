#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdint>

using namespace std;

const long long P = 31;

long long ComputeHash(const string &s) {
    long long hash = 0;
    for (int i=0; i<s.length(); i++) {
        hash = (hash * P + (s[i] - 'a' + 1));
    }
    return hash;
}

bool issubstr(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    long long hashT = ComputeHash(text.substr(0, m));
    long long hashP = ComputeHash(pattern);
    
    long long pm = 1;
    for (int i=0; i<m-1; i++) pm *= P;

    for (int i=0; i+m <= n; i++) {
        if (hashT == hashP) return true;
        if (i + m < n)
            hashT = (hashT - pm * (text[i] - 'a' + 1)) * P + (text[i + m] - 'a' + 1);
    }
    return false;
}

int main() {
    int n; 
    cin >> n;
    vector<string> v(n);
    int minsize = INT32_MAX;
    string minstr;
    for (int i=0; i<n; i++) {
        string s; 
        cin >> s;
        if (minsize > s.length()) {
            minsize = s.length();
            minstr = s;
        }
        v[i] = s;
    }
    int maxsize = 0;
    string res = "";
    for (int i=0; i<minsize; i++) {
        for (int j=i; j<minsize; j++) {
            string sub = minstr.substr(i, minsize - j);
            bool ok = true;
            for (int k=0; k<n; k++) {
                if (!issubstr(v[k], sub)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if (maxsize < sub.length()) {
                    maxsize = sub.length();
                    res = sub;
                }
            }
        }
    }
    cout << res;
}