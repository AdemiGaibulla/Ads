#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int l = 0;
    int length = n + 1;
    long long sum = 0;

    for (int r = 0; r < n; r++) {
        sum += v[r];
        while (sum >= k) {
            length = min(length, r - l + 1);
            sum -= v[l];
            l++;
        }
    }

    if (length == n + 1) cout << -1;
    else cout << length;
}
