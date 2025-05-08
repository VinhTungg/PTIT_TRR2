#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, cnt = 0, vertex, startVertex, endVertex;
vector<vector<int>> edges, adj;
vector<bool> visited(105, false);
vector<int> path;

bool findPath(int st, int en){
    if(st == en){
        path.emplace_back(en);
        cerr << en << ' ';
        return true;
    }
    visited[st] = true;
    for(auto neighbor : edges[st]){
        if(!visited[neighbor]){
            if(findPath(neighbor, en)){
                path.emplace_back(st);
                cerr << st << ' ';
                return true;
            }
        }
    }
    return false;
}

int main(){
    boost;
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> t >> vertex >> startVertex >> endVertex;
    edges.resize(vertex + 1);
    adj.resize(vertex + 1, vector<int>(vertex + 1, 0));
    for(int i = 1; i <= vertex; ++i){
        for(int j = 1; j <= vertex; ++j){
            cin >> adj[i][j];
            if(adj[i][j]){
                edges[i].emplace_back(j);
                edges[j].emplace_back(i);
            }
        }
    }
    if(t == 1){
        int res = 0;
        for(int i = 1; i <= vertex; ++i){
            res += adj[startVertex][i] * adj[i][endVertex];
        }
        cout << res;
    }else{
        if(findPath(startVertex, endVertex)){
            reverse(path.begin(), path.end());
            for(auto i : path) cout << i << ' ';
        }else cout << "0";
    }
}