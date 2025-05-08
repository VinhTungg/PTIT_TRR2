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
    cin >> t;
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> adj(vertex + 1, vector<int>(vertex + 1, 0));
    for(int i = 1; i <= edge; ++i){
        int startVertex, endVertex, weight;
        cin >> startVertex >> endVertex >> weight;
        adj[startVertex][endVertex] = weight;
        adj[endVertex][startVertex] = weight;
    }
    if(t == 1){
        for(int i = 1; i <= vertex; ++i){
            int deg = 0;
            for(int j = 1; j <= vertex; ++j){
                if(adj[i][j]) ++deg;
            }
            cout << deg << ' ';
        }
    }else{
        cout << vertex << endl;
        for(int i = 1; i <= vertex; ++i){
            for(int j = 1; j <= vertex; ++j){
                if(adj[i][j]) cout << adj[i][j] << ' ';
                else cout << (i == j ? 0 : LIMIT) << ' ';
            }
            cout << endl;
        }
    }
}