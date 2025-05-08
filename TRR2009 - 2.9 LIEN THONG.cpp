#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, vertex;
vector<bool> visited(105, false);
vector<vector<int>> edges;

void DFS(int u, vector<int> &component){
    visited[u] = true;
    component.emplace_back(u);
    for(auto v : edges[u]){
        if(!visited[v]){
            DFS(v, component);
        }
    }
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    boost;
    cin >> vertex;
    edges.resize(vertex + 1);
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
            DFS(i, component);
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