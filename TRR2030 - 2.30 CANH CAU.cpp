#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, vertex;
vector<vector<int>> adj;

int countComponent(){
    vector<bool> visited(vertex + 1, false);
    int comps = 0;
    queue<int> q;
    for(int i = 1; i <= vertex; ++i){
        if(!visited[i]){
            ++comps;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int curVertex = q.front();
                q.pop();
                for(int neighbor = 1; neighbor <= vertex; ++neighbor){
                    if(adj[curVertex][neighbor] and !visited[neighbor]){
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    return comps;
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    boost;
    cin >> vertex;
    adj.resize(vertex + 1, vector<int>(vertex + 1, 0));
    for(int i = 1; i <= vertex; ++i){
        for(int j = 1; j <= vertex; ++j){
            cin >> adj[i][j];
        }
    }
    int cntComponent = countComponent();
    vector<pair<int, int>> res;
    for(int i = 1; i <= vertex; ++i){
        for(int j = i + 1; j <= vertex; ++j){
            if(adj[i][j]){
                adj[i][j] = adj[j][i] = 0;
                if(countComponent() > cntComponent) res.emplace_back(i, j);
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    cout << res.size() << endl;
    if(res.size()){
        sort(res.begin(), res.end());
        for(auto &vertex : res) cout << vertex.first << ' ' << vertex.second << endl;
    }
}