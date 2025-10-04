#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch1 (vector<int>& a, int n, int r){
    int left = 0;
    int right = n-1;
    int answer = n;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(a[mid] > r){
            answer = mid;
            right = mid -1;
        }
        else left = mid +1;
    }
    return answer;
}

int BinarySearch2(vector<int>& a, int n, int l){
    int left = 0;
    int right = n;
    int answer = n-1;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(a[mid]>=l){
            answer = mid;
            right = mid -1;
        }
        else left = mid +1;
    }
    return answer;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt1 = BinarySearch1(a, n, r1) - BinarySearch2(a, n, l1);

        int cnt2 = BinarySearch1(a, n, r2) - BinarySearch2(a, n, l2);

        int L = max(l1, l2);
        int R = min(r1, r2);
        int intersection = 0;
        if (L <= R) {
            intersection = BinarySearch1(a, n, R) - BinarySearch2(a, n, L);
        }

        cout << cnt1 + cnt2 - intersection << endl;
    }
}
