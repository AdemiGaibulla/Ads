#include <iostream>
#include <cmath>

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
    if(prime(n)==true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}