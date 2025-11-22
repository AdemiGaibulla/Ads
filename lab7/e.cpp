#include <iostream>
#include <vector>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b, int m) {
    if (a[m] != b[m]) return a[m] > b[m];
    for (int i=0; i<m; i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

void merge(vector<vector<int>>& v, int left, int mid, int right, int m) {
    int n1 = mid - left +1;
    int n2 = right - mid;

    vector<vector<int>> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = v[left + i];
    for (int i = 0; i < n2; i++) R[i] = v[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (comp(L[i], R[j], m)) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }
    while (i < n1) {
        v[k] = L[i];
        k++;
        i++;
    }
    while (j < n2){
        v[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(vector<vector<int>>& v, int left, int right, int m) {
    if (left < right) {
        int mid = left + (right - left)/2;
        mergeSort(v, left, mid, m);
        mergeSort(v, mid + 1, right, m);
        merge(v, left, mid, right, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            sum += v[i][j];
        }
        v[i][m] = sum;
    }

    mergeSort(v, 0, n-1, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
