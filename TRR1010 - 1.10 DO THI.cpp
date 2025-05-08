#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;
const int LIMIT = 1e4;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    boost;
    int n; 
    cin >> t >> n;
    vector<vector<int>> adj(n + 1), edges(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x != 0 and x != LIMIT){
                adj[i].push_back(j);
            }
            edges[i][j] = x;
        }
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i){
            cout << adj[i].size() << " ";
        }
    }else{
        set<tuple<int, int, int>> se;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i < j and edges[i][j] != 0 and edges[i][j] != LIMIT) se.insert({i, j, edges[i][j]});
            }
        }
        cout << n << ' ' << se.size() << endl;
        for(auto &x : se){
            cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
        }
    }
}