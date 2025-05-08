#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int n, u;
vector<vector<int>> edge(105, vector<int>(105, 0)), ans;
vector<int> path;
vector<bool> visited(105, false);

void Try(int i, int cnt = 1){
    if(cnt == n){
        if(edge[i][u]){
            path.emplace_back(u);
            ans.emplace_back(path);
            path.pop_back();
        }
        return;
    }
    for(int j = 1; j <= n; j++){
        if(edge[i][j] and !visited[j]){
            visited[j] = true;
            path.emplace_back(j);
            Try(j, cnt + 1);
            visited[j] = false;
            path.pop_back();
        }
    }
}

int main(){
    boost;
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    cin >> n >> u;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> edge[i][j];
        }
    }
    visited[u] = true;
    path.emplace_back(u);
    Try(u);
    cout << ans.size() << endl;
    if(ans.size()) for(auto x : ans){
        for(int y : x) cout << y << " ";
        cout << endl;
    }
}