#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2; i<n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

bool isPrimeopt(int n){
    if(n<=1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

vector<int> prime(int n){
    vector<bool> isprime(n+1,true);
    isprime[0] = isprime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(isprime[i]){
            for(int j=i*i; j<=n; j+=i){
                isprime[j] = false;
            }
        }
    }

    vector<int> result;
    for(int i=0; i<isprime.size(); i++){
        if(isprime[i]) result.push_back(i);
    }
}