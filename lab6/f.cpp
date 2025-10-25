#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

double gpacount(vector<pair<string, double>>& gpa) {
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

int partition(vector<pair<string, double>>& v, int low, int high) {
    pair<string, double> pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (comp(v[j], pivot)) {
            i = i + 1;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSort(vector<pair<string, double>>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
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

        double average = gpacount(gpa);
        v.push_back({fullname, average});
    }

    quickSort(v, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(3);
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
