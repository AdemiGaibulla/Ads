#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

double gpa_count(vector<pair<string, double>>& gpa) {
    double credit_total = 0;
    double total = 0;

    for (int i = 0; i < gpa.size(); i++) {
        double grade = 0;

        if (gpa[i].first == "A+") grade = 4.00;
        else if (gpa[i].first == "A") grade = 3.75;
        else if (gpa[i].first == "B+") grade = 3.50;
        else if (gpa[i].first == "B") grade = 3.00;
        else if (gpa[i].first == "C+") grade = 2.50;
        else if (gpa[i].first == "C") grade = 2.00;
        else if (gpa[i].first == "D+") grade = 1.50;
        else if (gpa[i].first == "D") grade = 1.00;
        else if (gpa[i].first == "F") grade = 0.00;

        total = total + grade * gpa[i].second;
        credit_total = credit_total + gpa[i].second;
    }

    double average;
    if (credit_total == 0) {
        average = 0;
    } else {
        average = total / credit_total;
    }

    return average;
}

bool comp(pair<string, double>& a, pair<string, double>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

void merge(vector<pair<string, double>>& v, int left, int mid, int right){
    int n1 = mid - left+1;
    int n2 = right - mid;

    vector<pair<string, double>> L(n1);
    vector<pair<string, double>> R(n2);

    for(int i=0; i<n1; i++) L[i] = v[left+i];
    for(int i=0; i<n2; i++) R[i] = v[mid+i+1];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(comp(L[i],R[j])){
            v[k] = L[i];
            i++;
        }
        else{
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        v[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<string, double>>& v, int left, int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, double>> v;

    for (int i = 0; i < n; i++) {
        string fname, lname;
        int discipline;
        cin >> fname >> lname >> discipline;

        string fullname = fname + " " + lname;
        vector<pair<string, double>> gpa;

        for (int j = 0; j < discipline; j++) {
            string mark;
            double credit;
            cin >> mark >> credit;
            gpa.push_back({mark, credit});
        }

        double average = gpa_count(gpa);
        v.push_back({fullname, average});
    }

    mergeSort(v, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(3);
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
