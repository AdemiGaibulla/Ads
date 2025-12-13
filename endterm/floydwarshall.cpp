#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> FloydWarshall(int n, vector<vector<long long>> &g){
    const long long INF = 1e18;
    vector<vector<long long>> dist = g;

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(dist[i][i] < 0){
            cout<<"Negative cycle";
            break;
        }
    }
    return dist;
}