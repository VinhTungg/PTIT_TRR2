#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m;
vector<int> par, vs;
vector<vector<int>> ke;

void DFS(int u) {
    vs[u] = 1;
    for (auto &v : ke[u]) {
        if (!vs[v]) DFS(v);
    }
}

int check() {
    int cnt = 0;
    for (int v = 1; v <= n; ++v) {
        if (!vs[v]) {
            ++cnt;
            DFS(v);
        }
    }
    return cnt == 1;
}

int Find(int u) {
    if (u == par[u]) return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return false;
    if (u < v) swap(u, v);
    par[v] = u;
    return true;
}

struct Edges{
    int u, v, w, id;
};
vector<Edges> adj;

bool cmp(Edges &a, Edges &b) {
    return (a.w != b.w ? a.w < b.w : a.id < b.id);
}

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    boost;
    //cin >> t;
    while (t--) {
        cin >> n >> m;
        par.resize(n + 1);
        vs.assign(n + 1, 0);
        iota(par.begin(), par.end(), 0);
        ke.resize(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            ke[u].push_back(v);
            ke[v].push_back(u);
            adj.push_back({u, v, w, i});
        }
        if (!check()) {
            return cout << 0, 0;
        }
        sort(adj.begin(), adj.end(), cmp);
        vector<Edges> ans;
        int wt = 0;
        for (auto &x : adj) {
            if (Union(x.u, x.v)) {
                wt += x.w;
                ans.push_back({min(x.u, x.v), max(x.u, x.v), x.w, x.id});
            }
            if (ans.size() == n - 1) break;
        }
        cout << wt << endl;
        for (auto &x : ans) {
            cout << x.u << ' ' << x.v << ' ' << x.w << endl;
        }
    }
    time;
}