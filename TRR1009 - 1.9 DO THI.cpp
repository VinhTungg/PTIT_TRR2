#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

int main(){
    boost;
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    int n, m;
    cin >> t >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> m;
        adj[i].reserve(m);
        while(m--){
            int x; cin >> x;
            adj[i].push_back(x);
        }
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i){
            cout << adj[i].size() << " ";
        }
    }else{
        set<pair<int, int>> edges;
        for(int u = 1; u <= n; ++u){
            for(int v : adj[u]){
                edges.insert({min(u, v), max(u, v)});
            }
        }
        vector<pair<int, int>> E(edges.begin(), edges.end());
        m = E.size();
        cout << n << " " << m << endl;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < m; ++j){
                auto [u, v] = E[j];
                cout << (i == u or i == v) << ' ';
            }
            cout << endl;
        }
    }
}