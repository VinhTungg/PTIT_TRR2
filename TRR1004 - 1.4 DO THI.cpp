#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t, n, m;
vector<vector<int>> edge(105), used;

int main(){
    boost;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n >> m;
    used.resize(n + 1, vector<int>(n + 1, 0));
    while(m--){
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
        used[x][y] = used[y][x] = 1;
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i) cout << edge[i].size() << " ";
    }
    else{
        cout << n << endl;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cout << used[i][j] << " ";           
            }
            cout << endl;
        }
    }
}