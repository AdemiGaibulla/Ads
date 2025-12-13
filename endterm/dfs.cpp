#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void DFS(vector<vector<int>> &graph, int node){
    vector<bool> visited(graph.size(), false);
    stack<int> st;

    visited[node] = true;
    st.push(node);

    while(!st.empty()){
        int s = st.top();
        st.pop();

        cout<<s<<" ";

        for(int i=graph[s].size()-1; i>=0; i--){
            int n = graph[s][i];
            if(!visited[n]){
                visited[n] = true;
                st.push(n);
            }
        }
    }
}