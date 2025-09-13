#include <iostream>
#include <vector>

using namespace std;

bool prime(int n){
    if (n < 2){
        return false;
    }
    if (n==2 || n==3){
        return true;
    }
    for(int i=2; i < n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<long long> prime_numbers;
    vector<long long> superprimes;
    for(int i=1;i<10000;i++){
        if(prime(i)) prime_numbers.push_back(i);
    }
    for(int i=0;i<prime_numbers.size();i++){
        if(prime(i+1)) superprimes.push_back(prime_numbers[i]);
    }    
    cout<<superprimes[n-1];
}