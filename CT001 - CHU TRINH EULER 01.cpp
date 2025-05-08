#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
vector<vector<int>> adj(105, vector<int>());
vector<int> degree(105, 0);
vector<vector<bool>> used(105, vector<bool>(105, false));
vector<bool> visited(105, false);

void DFS(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

int CountComponent(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i);
            ++cnt;
        }
    }
    return cnt;
}

void FindPath(int u){
    stack<int> st;
    vector<int> path;
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        if(adj[v].size()){
            int tmp = adj[v].front();
            adj[v].erase(adj[v].begin());
            adj[tmp].erase(find(adj[tmp].begin(), adj[tmp].end(), v));
            st.push(tmp);
        }else{
            path.push_back(v);
            st.pop();
        }
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " ";
}

int main(){
    boost;
    cin >> t;
    int n, m, u;
    cin >> n >> m;
    if(t == 2) cin >> u;
    int a, b;
    while(m--){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    if(t == 1){
        int odd = 0;
        for(int i = 1; i <= n; i++){
            if(degree[i] % 2){
                ++odd;
            }
        }
        if(CountComponent(n) == 1){
            if(!odd) cout << "1";
            else if(odd == 2 or odd == 1) cout << "2";
            else cout << "0";
        }else cout << "0";
    }else{
        FindPath(u);
    }
}