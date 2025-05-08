// NOT AC (WRONG TEST)
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
vector<int> path, parent(105, -1);

bool findPath(int st, int en){
    queue<int> q;
    q.push(st);
    visited[st] = true;
    while(!q.empty()){
        int curVertex = q.front();
        if(curVertex == en) break;
        q.pop();
        for(auto neighbor : edges[curVertex]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                parent[neighbor] = curVertex;
                q.push(neighbor);
            }
        }
    }
    if(!visited[en]) return false;
    for(int i = en; i != -1; i = parent[i]) path.emplace_back(i);
    reverse(path.begin(), path.end());
    return true;
}

int main(){
    boost;
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    cin >> t >> vertex >> startVertex >> endVertex;
    edges.resize(vertex + 1);
    adj.resize(vertex + 1, vector<int>(vertex + 1, 0));
    for(int i = 1; i <= vertex; ++i){
        for(int j = 1; j <= vertex; ++j){
            cin >> adj[i][j];
            if(adj[i][j]){
                edges[i].emplace_back(j);
            }
        }
    }
    if(t == 1){
        for(int i = 1; i <= vertex; ++i){
            cnt += adj[startVertex][i] * adj[i][endVertex];
        }
        cout << cnt;
    }else{
        if(findPath(startVertex, endVertex)){
            for(auto i : path) cout << i << ' ';
        }else cout << "0";
    }
}
