#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> Dijkstra(int n, vector<vector<pair<int,int>>> &g, int start){
    const long long INF = 1e18;
    vector<long long> dist(n,INF);
    dist[start] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        auto [d,v] = pq.top();
        pq.pop();

        if(d > dist[v]) continue;

        for(auto [to, w] : g[v]){
            if(dist[v] + w < dist[to]){
                dist[to] = dist[v] + w;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}