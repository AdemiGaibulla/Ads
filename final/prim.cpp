#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long Prim(int n, vector<vector<pair<int,int>>>& g) {
    vector<bool> used(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0}); // (вес, вершина)
    long long sum = 0;

    while(!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if(used[v]) continue;
        used[v] = true;
        sum += w;

        for(auto [to, wt] : g[v]) {
            if(!used[to]) {
                pq.push({wt, to});
            }
        }
    }
    return sum;
}
