#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int test = 1, n, s, t;
vector<vector<int>> adj;

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    boost;
    // cin >> test;
    while (test--) {
        cin >> n >> s >> t;
        adj.resize(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> adj[i][j];
            }
        }
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(int v = 1; v <= n; ++v){
                if(adj[u][v] != 0 and adj[u][v] != 10000 and dist[v] > dist[u] + adj[u][v]){
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        int tmp = t;
        vector<int> path;
        while(tmp != -1){
            path.push_back(tmp);
            tmp = parent[tmp];
        }
        reverse(path.begin(), path.end());
        if(dist[t] == INT_MAX) cout << 0;
        else{
            cout << dist[t] << endl;
            for(auto &vertex : path) cout << vertex << ' ';
        }
    }
    time;
}