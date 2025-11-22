#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int start, vector<vector<int>> &adj, vector<bool> visited){
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!(q.empty())){
        int v = q.front();
        q.pop();
        cout<<v<<" ";

        for(int u : adj[v]){
            if(!(visited[u])){
                visited[u] = true;
                q.push(u);
            }
        }
    }
}