#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;

int main(){
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    boost;
    int t, n, u = 0;
    cin >> t >> n;
    if(t == 2) cin >> u;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; 
            cin >> c;
            adj[i][j] = c - '0';
            if (adj[i][j]){
                outdeg[i]++;
                indeg[j]++;
            }
        }
    }
    if(t == 1){
        int plus1 = 0, minus1 = 0;
        bool bad = false;
        for(int i = 1; i <= n; i++){
            int d = outdeg[i] - indeg[i];
            if      (d ==  1) plus1++;
            else if (d == -1) minus1++;
            else if (d !=  0) bad = true;
        }
        vector<int> nz;
        for(int i = 1; i <= n; i++) 
            if(outdeg[i] + indeg[i] > 0) 
                nz.push_back(i);
        auto strongDFS = [&](int s, vector<bool>& vis, auto &G){
            stack<int> st; 
            st.push(s);
            vis[s] = true;
            while(!st.empty()){
                int v = st.top(); st.pop();
                for (int w = 1; w <= n; w++){
                    if (G[v][w] && !vis[w]){
                        vis[w] = true;
                        st.push(w);
                    }
                }
            }
        };
        auto weakDFS = [&](int s, vector<bool>& vis){
            stack<int> st; 
            st.push(s);
            vis[s] = true;
            while(!st.empty()){
                int v = st.top(); st.pop();
                for (int w = 1; w <= n; w++) {
                    if(!vis[w] && (adj[v][w] or adj[w][v])){
                        vis[w] = true;
                        st.push(w);
                    }
                }
            }
        };
        bool ok = false;
        if(nz.empty()) ok = !bad and plus1 == 0 and minus1 == 0;
        else if(plus1 == 0 and minus1 == 0 and !bad){
            int s = nz[0];
            vector<vector<int>> rev(n+1, vector<int>(n+1));
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if (adj[i][j]) rev[j][i] = 1;
            vector<bool> vis1(n + 1, false), vis2(n + 1, false);
            strongDFS(s, vis1, adj);
            strongDFS(s, vis2, rev);
            ok = true;
            for(int v : nz){
                if(!vis1[v] or !vis2[v]){
                    ok = false;
                    break;
                }
            }
        }
        else if(plus1 == 1 and minus1 == 1 and !bad){
            int s = -1;
            for (int i = 1; i <= n; i++)
                if(outdeg[i] - indeg[i] == 1){ 
                    s = i; break;
                }
            if(s < 0) s = nz[0];
            vector<bool> vis(n + 1,false);
            weakDFS(s, vis);
            ok = true;
            for(int v : nz)
                if(!vis[v]){
                    ok = false;
                    break;
                }
        }
        if (!ok) cout << 0 << "\n";
        else if(plus1 == 0 and minus1 == 0) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    else{
        auto g = adj;
        vector<int> st, circuit;
        st.push_back(u);
        while (!st.empty()){
            int v = st.back(), w = 1;
            while (w <= n && g[v][w] == 0) w++;
            if (w <= n){
                g[v][w]--;
                st.push_back(w);
            }else{
                circuit.push_back(v);
                st.pop_back();
            }
        }
        for(int i = int(circuit.size()) - 1; i >= 0; i--)
            cout << circuit[i] << ' ';
    }
}
