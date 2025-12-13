#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent(200000);

int find_parents(int v){
    if(parent[v] == v) return v;
    return parent[v] = find_parents(parent[v]);
}

void union_find(int a, int b){
    a = find_parents(a);
    b = find_parents(b);

    if(a!=b) parent[a] = b;
}

long long Kruskal(vector<pair<int,pair<int,int>>> &edgelist, int n){
    for(int i=0; i<n; i++) parent[i] = i;

    sort(edgelist.begin(), edgelist.end());

    long long sum = 0;
    int cnt = 0;

    for(int i=0; i<edgelist.size(); i++){
        int weight = edgelist[i].first;
        int a = edgelist[i].second.first;
        int b = edgelist[i].second.second;

        if(find_parents(a) != find_parents(b)){
            sum += weight;
            union_find(a,b);
            cnt++;
            if(cnt == n-1) break;
        }
    }
    return sum;
}