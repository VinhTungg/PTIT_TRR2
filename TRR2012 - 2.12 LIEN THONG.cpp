#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, vertex;
vector<bool> visited;
vector<vector<int>> edges;

void BFS(int u, vector<int> &component){
   visited[u] = true;
   component.emplace_back(u);
   queue<int> q;
   q.push(u);
   while(!q.empty()){
       int curVertex = q.front();
       q.pop();
       for(auto neighbor : edges[curVertex]){
           if(!visited[neighbor]){
               visited[neighbor] = true;
               component.emplace_back(neighbor);
               q.push(neighbor);
           }
       }
   }
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    boost;
    cin >> vertex;
    edges.resize(vertex + 1);
    visited.resize(vertex + 1, false);
    for(int i = 1; i <= vertex; ++i){
        for(int j = 1; j <= vertex; ++j){
            int x; cin >> x;
            if(x){
                edges[i].emplace_back(j);
                edges[j].emplace_back(i);
            }
        }
    }
    int cntComponent = 0;
    vector<vector<int>> connectedComponent;
    for(int i = 1; i <= vertex; ++i){
        if(!visited[i]){
            vector<int> component;
            BFS(i, component);
            connectedComponent.emplace_back(component);
            ++cntComponent;
        }
    }
    cout << cntComponent << endl;
    for(auto component : connectedComponent){
        sort(component.begin(), component.end());
        for(auto vertex : component) cout << vertex << ' ';
        cout << endl;
    }
}