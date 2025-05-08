#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    boost;
    cin >> t;
    int n; cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    if(t == 1){
        vector<int> degIn(n + 1, 0), degOut(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                int x; cin >> x;
                if(x){
                    ++degOut[i];
                    ++degIn[j];
                }
            }
        }
        for(int i = 1; i <= n; ++i) cout << degIn[i] << " " << degOut[i] << endl;
    }else{
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> adj[i][j];
                cnt += adj[i][j];
            }
        }
        cout << n << ' ' << cnt << endl;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j) {
                if(adj[i][j]) cout << i << ' ' << j << endl;
            }
        }
    }
}