#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;

int n, s;
vector<set<int>> adj;

void check_euler_existence(){
    cin >> n;
    adj.assign(n + 1, set<int>());
    string line_buffer;
    for(int i = 1; i <= n; ++i){
        getline(cin >> ws, line_buffer);
        stringstream ss(line_buffer);
        string token;
        ss >> token;
        while(ss >> token) adj[i].insert(stoi(token));
    }
    vector<int> in_degree(n + 1, 0);
    vector<int> out_degree(n + 1, 0);
    for(int u = 1; u <= n; ++u){
        out_degree[u] = adj[u].size();
        for(int v : adj[u]) in_degree[v]++;
    }
    int c1 = 0, c2 = 0;
    for(int i = 1; i <= n; ++i){
        if(abs(in_degree[i] - out_degree[i]) > 1) ++c1;
        if(abs(in_degree[i] - out_degree[i]) == 1) ++c2;
    }
    if(c1 > 0) cout << 0 << endl;
    else if(c2 == 0) cout << 1 << endl;
    else if(c2 == 2) cout << 2 << endl;
    else cout << 0 << endl;
}

void find_euler_path(){
    cin >> n >> s;
    adj.assign(n + 1, set<int>());
    string line_buffer;
    for(int i = 1; i <= n; ++i){
        getline(cin >> ws, line_buffer);
        stringstream ss(line_buffer);
        string token;
        ss >> token;
        while(ss >> token) adj[i].insert(stoi(token));
    }
    stack<int> stk;
    vector<int> euler_path;
    stk.push(s);
    while(!stk.empty()){
        int u_curr = stk.top();
        if(!adj[u_curr].empty()){
            int v_next = *adj[u_curr].begin();
            adj[u_curr].erase(adj[u_curr].begin());
            stk.push(v_next);
        }else{
            stk.pop();
            euler_path.push_back(u_curr);
        }
    }
    reverse(euler_path.begin(), euler_path.end());
    for(size_t i = 0; i < euler_path.size(); ++i) 
        cout << euler_path[i] << (i == euler_path.size() - 1 ? "" : " ");
    cout << endl;
}

int main() {
    boost;
    int t;
    cin >> t;
    if(t == 1) check_euler_existence();
    else find_euler_path();
}
