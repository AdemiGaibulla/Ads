#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> numbers;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        numbers.push_back(element);
    }
    int k;
    cin>>k;
    vector<int> distance;
    for(int i=0;i<n;i++){
        distance.push_back(abs(numbers[i]-k));
    }
    int index=0;
    int min=distance[0];
    for(int i=0;i<n;i++){
        if(min>distance[i]){
            min=distance[i];
            index=i;
        } 
    }
    cout<<index;


}