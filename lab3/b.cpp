#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long left = arr[0], right = 0;
    for (long long i = 0; i < n; i++) {
        if (arr[i] > left) left = arr[i];
        right += arr[i];
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long sum = 0, cnt = 1;

        for (long long i = 0; i < n; i++) {
            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                cnt++;
                sum = arr[i];
            }
        }

        if (cnt <= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}
