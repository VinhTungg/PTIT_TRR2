#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
const int MAX = 105;
int t = 1, n, s;
int a[MAX][MAX], vs[MAX];

void DFS(int u) {
    vs[u] = 1;
    for (int v = 1; v <= n; ++v) {
        if (!vs[v] and a[u][v] != 0 and a[u][v] != 1e4) {
            DFS(v);
        }
    }
}

int check() {
    memset(vs, 0, sizeof(vs));
    int cnt = 0;
    for (int v = 1; v <= n; ++v) {
        if (!vs[v]) {
            ++cnt;
            DFS(v);
        }
    }
    return cnt == 1;
}

void prim(int s) {
    memset(vs, 0, sizeof(vs));
    vs[s] = 1;
    int wt = 0;
    vector<tuple<int, int, int>> ans;
    while (ans.size() < n - 1) {
        int st, en, min_wt = 1e4;
        for (int i = 1; i <= n; ++i) {
            if (vs[i]) {
                for (int v = 1; v <= n; ++v) {
                    if (!vs[v] and a[i][v] != 0 and a[i][v] != 10000 and min_wt > a[i][v]) {
                        st = i;
                        en = v;
                        min_wt = a[i][v];
                    }
                }
            }
        }
        wt += min_wt;
        vs[en] = 1;
        ans.emplace_back(min(st, en), max(st, en), min_wt);
    }
    cout << wt << endl;
    for (auto &x : ans) {
        int u, v, w;
        tie(u, v, w) = x;
        cout << u << ' ' << v << ' ' << w << endl;
    }
    return;
}

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    boost;
    //cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }
        if (!check()) return cout << 0, 0;
        prim(s);
    }
    // time;
}