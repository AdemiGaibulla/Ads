#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        arr[i]=element;
    }
    int rounds;
    cin>>rounds;
    for(int i=0; i<rounds; i++){
        int power;
        cin>>power;
        int cnt=0;
        int sum=0;
        for(int j=0; j<n; j++){
            if(power>=arr[j]){
                cnt++;
                sum+=arr[j];
            }
        }
        cout<<cnt<<" "<<sum<<endl;
    }
}