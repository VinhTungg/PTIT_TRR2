#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, u, MinVal = INT_MAX, ans = INT_MAX;
vector<vector<int>> edge(105, vector<int>(105, 0));
vector<int> path, res;
vector<bool> visited(105, false);

void Try(int i, int cnt = 1, int sum = 0){
    if(cnt == n){
        if(edge[i][u] != 0 and edge[i][u] != 10000){
            if(ans > sum + edge[i][u]){
                path.push_back(u);
                ans = sum + edge[i][u];
                res = path;
                path.pop_back();
            }
        }
        return;
    }
    for(int j = 1; j <= n; ++j){
        if(!visited[j] and edge[i][j] != 0 and edge[i][j] != 10000 and sum + (n - cnt) * MinVal < ans){
            visited[j] = true;
            path.push_back(j);
            Try(j, cnt + 1, sum + edge[i][j]);
            visited[j] = false;
            path.pop_back();
        }
    }
}

int main(){
    boost;
    cin >> n >> u;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> edge[i][j];
            if(edge[i][j] != 0 and edge[i][j] != 10000) MinVal = min(MinVal, edge[i][j]);
        }
    }
    visited[u] = true;
    path.emplace_back(u);
    Try(u);
    if(ans != INT_MAX){
        cout << ans << endl;
        for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    }
    else cout << 0;
}