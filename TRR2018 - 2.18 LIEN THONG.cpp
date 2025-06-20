#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, vertex;
vector<vector<int>> adj, adj_rev;
vector<bool> vs;

void dfs1(int u) {
    vs[u] = true;
    for (auto &v : adj[u]) {
        if (!vs[v]) {
            dfs1(v);
        }
    }
}

void dfs2(int u) {
    vs[u] = true;
    for (auto &v : adj_rev[u]) {
        if (!vs[v]) {
            dfs2(v);
        }
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    boost;
    //cin >> t;
    while (t--) {
        cin >> vertex;
        adj.resize(vertex + 1);
        adj_rev.resize(vertex + 1);
        vs.resize(vertex + 1);
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                int x;
                cin >> x;
                if (x == 1) {
                    adj[i].push_back(j);
                    adj_rev[j].push_back(i);
                }
            }
        }
        dfs1(1);
        for (int i = 1; i <= vertex; ++i) {
            if (!vs[i]) {
                return cout << 0, 0;
            }
        }
        vs.assign(vertex + 1, false);
        dfs2(1);
        for (int i = 1; i <= vertex; ++i) {
            if (!vs[i]) {
                return cout << 2, 0;
            }
        }
        cout << 1;
    }
    time;
}