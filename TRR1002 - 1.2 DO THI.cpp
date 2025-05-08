#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t, n;
vector<vector<int>> edge;

int main(){
    boost;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n;
    edge.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x)
                edge[i].emplace_back(j);
        }
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i) cout << edge[i].size() << ' ';
    }else{
        cout << n << endl;
        for(int i = 1; i <= n; ++i){
            cout << edge[i].size() << ' ';
            for(auto &j : edge[i]) cout << j << ' ';
            cout << endl;
        }
    }
}