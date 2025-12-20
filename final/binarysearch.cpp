#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &v, int target){
    int left = 0;
    int right = v.size()-1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(v[mid] == target) return mid;
        else if(v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int firstOccurrence(vector<int> &v, int target){
    int left = 0;
    int right = v.size()-1;
    int ans = -1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(v[mid] == target){
            ans = mid;
            right = mid - 1;
        }
        else if(v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return ans;
}

int lastOccurrence(vector<int> &v, int target){
    int left = 0;
    int right = v.size() - 1;
    int ans = -1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(v[mid] == target){
            ans = mid;
            left = mid + 1;
        }
        else if(v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return ans;
}

int lowerBound(vector<int> &v, int target){
    int left = 0;
    int right = v.size() - 1;
    int ans = v.size();

    while(left <= right){
        int mid = left + (right - left)/2;
        if(v[mid] >= target){
            ans = mid;
            right =  mid - 1;
        }
        else left = mid + 1;
    }
    return ans;
}

int upperBound(vector<int> &v, int target){
    int left = 0;
    int right = v.size() - 1;
    int ans = v.size();

    while(left <= right){
        int mid = left + (right - left)/2;
        if(v[mid] > target){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return ans;
}