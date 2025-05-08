#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, vertex;
vector<bool> visited(105, false);
vector<vector<int>> edges, transposeEdges, adj;

int DFS_Count(int u, const vector<vector<int>> &adj){
    visited[u] = true;
    int cnt = 1;
    for(auto v : adj[u]){
        if(!visited[v]){
            cnt += DFS_Count(v, adj);
        }
    }
    return cnt;
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    boost;
    cin >> vertex;
    edges.resize(vertex + 1);
    transposeEdges.resize(vertex + 1);
    adj.resize(vertex + 1);
    for(int i = 1; i <= vertex; ++i){
        for(int j = 1; j <= vertex; ++j){
            int x; cin >> x;
            if(x){
                edges[i].emplace_back(j);
                transposeEdges[j].emplace_back(i);
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }
    int cntFirst = DFS_Count(1, edges);
    visited.assign(vertex + 1, false);
    int cntSecond = DFS_Count(1, transposeEdges);
    if(cntFirst == vertex and cntSecond == vertex) return cout << "1", 0;
    visited.assign(vertex + 1, false);
    int cntComponent = DFS_Count(1, adj);
    if(cntComponent == vertex) return cout << "2", 0;
    else cout << "0";
}