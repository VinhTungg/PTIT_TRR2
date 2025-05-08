#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t, n, m;
vector<vector<int>> adj(105);
vector<pair<int, int>> ans;

int main(){
    boost;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n >> m;
    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        ans.push_back({x, y});
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i){
            cout << adj[i].size() << " ";
        }
    }else{
        cout << n << ' ' << m << endl;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < m; ++j){
                if(ans[j].first == i || ans[j].second == i) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            cout << endl;
        }
    }
}