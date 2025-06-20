#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, st, en;
const int INF = 1e9;

struct Edges{
    int u, v, w;
};
vector<Edges> adj;

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    boost;
    //cin >> t;
    while (t--) {
        cin >> n >> st >> en;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x; cin >> x;
                if (x != 0 and x != 10000) {
                    adj.push_back({i, j, x});
                }
            }
        }
        vector<int> dist(n + 1, INF);
        vector<int> trace(n + 1, -1);
        dist[st] = 0;
        for (int i = 1; i < n; ++i) {
            for (auto &e : adj) {
                auto [u, v, w] = e;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    trace[v] = u;
                }
            }
        }
        for (auto &e : adj) {
            auto [u, v, w] = e;
            if (dist[v] > dist[u] + w) {
                return cout << -1, 0;
            }
        }
        if (dist[en] == INF) return cout << 0, 0;
        vector<int> path;
        int tmp = en;
        for (; tmp != -1; tmp = trace[tmp]) {
            path.push_back(tmp);
        }
        reverse(path.begin(), path.end());
        cout << dist[en] << endl;
        for (auto &x : path) cout << x << ' ';
    }
    time;
}