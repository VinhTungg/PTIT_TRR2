#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

using namespace std;

int t = 1, n;
const int INF = 1000000000;

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    boost;
    //cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1));
        vector<vector<int>> trace(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x;
                cin >> x;
                if (i == j) {
                    adj[i][j]   = 0;
                    trace[i][j] = j;
                }
                else if (x != 0 && x != 10000) {
                    adj[i][j]   = x;
                    trace[i][j] = j;
                }
                else {
                    adj[i][j]   = INF;
                    trace[i][j] = -1;
                }
            }
        }

        for (int k = 1; k <= n; ++k) {
            for (int u = 1; u <= n; ++u) {
                if (adj[u][k] == INF) continue;
                for (int v = 1; v <= n; ++v) {
                    if (adj[k][v] == INF) continue;
                    int via = adj[u][k] + adj[k][v];
                    if (via < adj[u][v]) {
                        adj[u][v]     = via;
                        trace[u][v]   = trace[u][k];
                    }
                }
            }
        }

        int max_wt = -1;
        int U = 0, V = 0;
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (u == v) continue;
                if (adj[u][v] < INF) {
                    if (adj[u][v] > max_wt or (adj[u][v] == max_wt and (u < U or (u == U and v < V)))) {
                        max_wt = adj[u][v];
                        U = u; V = v;
                    }
                }
            }
        }
        if (max_wt < 0) return cout << 0, 0;
        cout << U << ' ' << V << ' ' << max_wt << endl;
        vector<int> ans;
        int cur = U;
        ans.push_back(cur);
        while (cur != V) {
            cur = trace[cur][V];
            ans.push_back(cur);
        }
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
        }
    }
}
