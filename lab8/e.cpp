#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> hashes(n);
    for (int i=0; i<n; i++) {
        cin >> hashes[i];
    }

    string result = "";

    for (int i=0; i<n; i++) {
        long long previous_hash;
        if (i == 0) {
            previous_hash = 0;
        } else {
            previous_hash = hashes[i-1];
        }

        long long diff = hashes[i] - previous_hash;
        long long power = 1;
        for (int j=0; j<i; j++) {
            power = power * 2;
        }

        long long value = diff / power;
        char character = char(value + 97);

        result = result + character;
    }

    cout << result;

    return 0;
}
