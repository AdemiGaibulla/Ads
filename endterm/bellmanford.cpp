#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int from, to, weight;
};

vector<long long> BellmanFord(int n, vector<Edge> &edges, int start){
    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    dist[start] = 0;

    for(int i=0; i<n-1; i++){
        for(auto e : edges){
            if(dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]){
                dist[e.to] = dist[e.from] + e.weight;
            }
        }
    }
    for(auto e : edges){
        if(dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]){
            cout<<"Negative cycle";
            break;
        }
    }
    return dist;
}