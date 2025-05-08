#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t, n, m;
vector<vector<int>> edge(105);

int main(){
    boost;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n >> m;
    while(m--){
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i) cout << edge[i].size() << " ";
    }
    else{
        cout << n << endl;
        for(int i = 1; i <= n; ++i){
            cout << edge[i].size() << ' ';
            for(auto &j : edge[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
}