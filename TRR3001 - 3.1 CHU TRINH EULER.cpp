#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, u = 0;

int main(){
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> t >> n;
    if(t == 2) cin >> u;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<int> edge(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            adj[i][j] = c - '0';
            if(adj[i][j]) edge[i]++;
        }
    }
    if(t == 1){
        int odd = 0;
        for(int i = 1; i <= n; i++) 
            if(edge[i] % 2) 
                odd++;
        vector<bool> visited(n + 1, false);
        function<void(int)> dfs = [&](int v){
            visited[v] = true;
            for(int w = 1; w <= n; w++){
                if(adj[v][w] and !visited[w]){
                    dfs(w);
                }
            }
        };
        int st = -1;
        for(int i = 1; i <= n; i++){
            if(edge[i]){
                st = i;
                break;
            }
        }
        bool connected = true;
        if(st != -1){
            dfs(st);
            for(int i = 1; i <= n; i++){ 
                if(edge[i] and !visited[i]) {
                    connected = false;
                    break;
                }
            }
        }
        if(!connected) cout << "0";
        else if(!odd) cout << "1";
        else if(odd == 2) cout << "2";
        else cout << "0";
    }else{
        vector<vector<int>> tmp = adj;
        vector<int> path, st;
        st.push_back(u);
        while(!st.empty()){
            int v = st.back();
            int w = 1;
            while(w <= n and !tmp[v][w]) w++;
            if(w <= n){
                tmp[v][w] = tmp[w][v] = 0;
                st.push_back(w);
            }else{
                path.push_back(v);
                st.pop_back();
            }
        }
        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << (i ? " " : "\n");
        }
    }
}