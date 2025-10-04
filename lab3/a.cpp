#include <iostream>

using namespace std;

void LinearSearch(int target, int arr[800][800], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==target){
                cout<< i <<" "<< j <<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}

int main(){
    int numberoft;
    cin>>numberoft;
    int targets[numberoft];
    for(int i=0; i<numberoft; i++){
        int t;
        cin>>t;
        targets[i]=t;
    }
    int n,m;
    cin>>n>>m;
    int arr[800][800];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int element;
            cin>>element;
            arr[i][j]=element;
        }
    }
    for(int i=0; i<numberoft; i++){
        LinearSearch(targets[i], arr, n, m);
    }
}