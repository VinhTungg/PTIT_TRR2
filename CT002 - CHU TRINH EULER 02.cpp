#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, m, u;
vector<vector<int>> edge(105, vector<int>(105, 0));

void FindPath(int u){
    vector<vector<int>> tmp = edge;
    stack<int> st;
    vector<int> path;
    st.push(u);
    while(!st.empty()){
        int v = st.top();
        bool found = false;
        for(int u = 1; u <= n; ++u){
            if(tmp[v][u]){
                tmp[v][u]--;
                tmp[u][v]--;
                st.push(u);
                found = true;
                break;
            }
        }
        if(!found){
            path.push_back(v);
            st.pop();
        }
    }
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
}

int main(){
    cin >> t;
    cin >> n;
    if(t == 2) cin >> u;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> edge[i][j];
        }
    }
    if(t == 1){
        int odd = 0;
        for(int i = 1; i <= n; i++){
            int deg = 0;
            for(int j = 1; j <= n; j++){
                deg += edge[i][j];
            }
            if(deg % 2) odd++;
        }
        if(!odd) cout << "1";
        else if(odd == 2) cout << "2";
        else cout << "0";
    }else{
        FindPath(u);
    }
}