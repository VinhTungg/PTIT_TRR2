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

int countComponent(int bannedPoint){
    vector<bool> visited(vertex + 1, false);
    visited[bannedPoint] = true;
    int comps = 0;
    for(int i = 1; i <= vertex; ++i){
        if(!visited[i]){
            ++comps;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int curVertex = q.front();
                q.pop();
                for(auto neighbor : adj[curVertex]){
                    if(!visited[neighbor]){
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
    adj.resize(vertex + 1);
    for(int i = 1; i <= vertex; ++i){
        for(int j = 1; j <= vertex; ++j){
            int x; cin >> x;
            if(x){
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }
    int cntComponent = countComponent(0);
    vector<int> res;
    for(int i = 1; i <= vertex; ++i){
        if(countComponent(i) > cntComponent) res.emplace_back(i);
    }
    cout << res.size() << endl;
    if(res.size()){
        sort(res.begin(), res.end());
        for(auto &vertex : res) cout << vertex << ' ';
        cout << endl;
    }
}