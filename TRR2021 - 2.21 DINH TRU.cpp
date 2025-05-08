#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, vertex, timer;
vector<vector<int>> edges;
vector<int> disc, low, res, parent;
vector<bool> visited, ap;

void DFS(int u){
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int childCount = 0;
    for(auto v : edges[u]){
        if(!visited[v]){
            ++childCount;
            parent[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= disc[u] and parent[u] != -1) ap[u] = true;
            if(parent[u] == -1 and childCount > 1) ap[u] = true;
        }else if(v != parent[u]){
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    boost;
    cin >> vertex;
    edges.resize(vertex + 1);
    for(int i = 1; i <= vertex; ++i){
        for(int j = 1; j <= vertex; ++j){
            int x; cin >> x;
            if(x){
                edges[i].emplace_back(j);
                edges[j].emplace_back(i);
            }
        }
    }
    disc.resize(vertex + 1, 0);
    low.resize(vertex + 1, 0);
    parent.resize(vertex + 1, -1);
    visited.resize(vertex + 1, false);
    ap.resize(vertex + 1, false);
    timer = 0;
    for(int i = 1; i <= vertex; ++i){
        if(!visited[i]) DFS(i);
    }
    for(int i = 1; i <= vertex; ++i){
        if(ap[i]) res.emplace_back(i);
    }
    cout << res.size() << endl;
    if(res.size()){
        sort(res.begin(), res.end());
        for(auto &vertex : res) cout << vertex << ' ';
        cout << endl;
    }
}