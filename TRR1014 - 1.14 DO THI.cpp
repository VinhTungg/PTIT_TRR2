#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, vertex;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    boost;
    cin >> t >> vertex;
    vector<int> degOut(vertex + 1, 0), degIn(vertex + 1, 0);
    vector<vector<int>> adj(vertex + 1, vector<int>(vertex + 1, 0));
    set<pair<int, int>> edges;
    for(int i = 1; i <= vertex; ++i){
        for(int j = 1; j <= vertex; ++j){
            cin >> adj[i][j];
            degOut[i] += adj[i][j];
            degIn[j] += adj[i][j];
            if(adj[i][j]) edges.insert({i, j});
        }
    }
    if(t == 1){
        for(int i = 1; i <= vertex; ++i){
            cout << degIn[i] << ' ' << degOut[i] << endl;
        }
    }else{
        cout << vertex << ' ' << edges.size() << endl;
        for(int i = 1; i <= vertex; ++i){
            for(pair<int, int> j : edges){
                cout << (i == j.first ? 1 : (i == j.second ? -1 : 0)) << ' ';
            }
            cout << endl;
        }
    }
}