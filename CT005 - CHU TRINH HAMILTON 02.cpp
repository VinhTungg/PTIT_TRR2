#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m, start_node;
vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;
vector<vector<int>> ans;

void Try(int current_vertex, int count_visited_nodes) {
    if(count_visited_nodes == n){
        bool found_cycle_edge = false;
        for(int neighbor : adj[current_vertex]){
            if(neighbor == start_node){
                found_cycle_edge = true;
                break;
            }
        }
        if(found_cycle_edge){
            path.emplace_back(start_node);
            ans.emplace_back(path);
            path.pop_back();
        }
        return;
    }
    for(int next_vertex : adj[current_vertex]){
        if(!visited[next_vertex]){
            visited[next_vertex] = true;
            path.emplace_back(next_vertex);
            Try(next_vertex, count_visited_nodes + 1);
            visited[next_vertex] = false;
            path.pop_back();
        }
    }
}

int main(){
    boost;
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    cin >> n >> m >> start_node;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u_edge, v_edge;
        cin >> u_edge >> v_edge;
        adj[u_edge].push_back(v_edge);
        adj[v_edge].push_back(u_edge);
    }
    visited.assign(n + 1, false);
    path.clear();
    ans.clear();
    visited[start_node] = true;
    path.emplace_back(start_node);
    Try(start_node, 1);
    cout << ans.size() << endl;
    for(const auto& cycle_path : ans){
        for(size_t i = 0; i < cycle_path.size(); ++i){
            cout << cycle_path[i] << (i == cycle_path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}