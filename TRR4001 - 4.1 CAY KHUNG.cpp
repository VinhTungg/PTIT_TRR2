#include <bits/stdc++.h>
#define ll long long
#define boost cin.tie(0) -> sync_with_stdio(0)
#define time cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#define endl "\n"
#define MOD 1000000007
#define pii pair<int, int>

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
const int MAX = 105;
int t = 1, n, s;
int a[MAX][MAX], vs[MAX];
vector<pii> ans;

void dfs(int u) {
    vs[u] = 1;
    for (int v = 1; v <= n; ++v) {
        if (!vs[v] and a[u][v]) {
            dfs(v);
        }
    }
}

bool check_tplt() {
    memset(vs, 0, sizeof(vs));
    dfs(1);
    for (int v = 1; v <= n; ++v) {
        if (!vs[v]) 
            return false;
    }
    return true;
}

void DFS(int u) {
    vs[u] = 1;
    for (int v = 1; v <= n; ++v) {
        if (!vs[v] and a[u][v]) {
            ans.emplace_back(u, v);
            DFS(v);
        }
    }
}

void BFS(int u) {
    vs[u] = 1;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (!vs[i] and a[v][i]) {
                ans.emplace_back(v, i);
                q.push(i);
                vs[i] = 1;
            }
        }
    }
}

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    boost;
    cin >> t;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    if (!check_tplt())
        return cout << 0, 0;
        
    memset(vs, 0, sizeof(vs));
    if (t == 1) {
        DFS(s);
        if (ans.size() != n - 1) return cout << 0, 0;
        cout << ans.size() << endl;
        for (auto &x : ans) {
            cout << min(x.first, x.second) << ' ' << max(x.second, x.first) << endl;
        }
    } else {
        BFS(s);
        if (ans.size() != n - 1) return cout << 0, 0;
        cout << ans.size() << endl;
        for (auto &x : ans) {
            cout << min(x.first, x.second) << ' ' << max(x.second, x.first) << endl;
        }
    }
}