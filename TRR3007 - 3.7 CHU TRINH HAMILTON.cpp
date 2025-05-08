#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int n, u;
vector<vector<int>> g;
vector<vector<int>> ug;
vector<bool> visited;
vector<int> path;
vector<vector<int>> cycles;

void dfs_ham(int v, int depth){
    if(depth == n){
        for(int w : g[v]){
            if(w == u){
                auto cyc = path;
                cyc.push_back(u);
                cycles.push_back(cyc);
                break;
            }
        }
        return;
    }
    for(int w : g[v]){
        if(w == u) continue;
        if(!visited[w]){
            visited[w] = true;
            path[depth] = w;
            dfs_ham(w, depth + 1);
            visited[w] = false;
        }
    }
}

int main(){
    boost;
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> u;
    vector<string> mat(n);
    for(int i = 0; i < n; i++){
        mat[i].reserve(n);
        for(int j = 0; j < n; j++){
            char c; 
            cin >> c;
            mat[i].push_back(c);
        }
    }
    g.assign(n + 1, {});
    ug.assign(n + 1, {});
    vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mat[i - 1][j - 1] == '1'){
                g[i].push_back(j);
                outdeg[i]++; indeg[j]++;
                ug[i].push_back(j);
                ug[j].push_back(i);
            }
        }
        sort(g[i].begin(), g[i].end());
    }
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0 or outdeg[i] == 0){
            cout << 0 << "\n";
            return 0;
        }
    }
    vector<bool> seen(n + 1, false);
    queue<int> Q;
    seen[u] = true; Q.push(u);
    int cnt = 1;
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(int w : ug[v]){
            if(!seen[w]){
                seen[w] = true;
                Q.push(w);
                cnt++;
            }
        }
    }
    if(cnt < n){
        cout << 0 << "\n";
        return 0;
    }
    visited.assign(n + 1, false);
    path.assign(n, 0);
    path[0] = u;
    visited[u] = true;
    dfs_ham(u, 1);
    if(cycles.empty()){
        cout << 0 << "\n";
        return 0;
    }
    sort(cycles.begin(), cycles.end());
    for(auto &cyc : cycles){
        for(int i = 0; i < (int)cyc.size(); i++)
            cout << cyc[i] << (i + 1 < (int)cyc.size() ? ' ' : '\n');
    }
    cout << cycles.size() << "\n";
    return 0;
}
