//You have one letter. Your task is to find "balanced" char in array. "Balanced" char is the smallest in array, but more than your letter.
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    char letter;
    cin>>letter;
    for(int i=0;i<n;i++){
        if(letter<v[i]){
            cout<<v[i];
            return 0;
        }
    }
    cout<<v[0];
}