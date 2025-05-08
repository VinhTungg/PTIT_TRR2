#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t, n;
vector<vector<int>> adj(105);
vector<vector<bool>> used(105, vector<bool>(105, false));
vector<pair<int, int>> ans;

int main(){
    boost;
    cin >> t >> n;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x;
            cin >> x;
            if(x){
                adj[i].push_back(j);
                if(!used[i][j]){
                    used[i][j] = true;
                    used[j][i] = true;
                    ++cnt;
                    ans.push_back({i, j});
                }
            }
        }
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i){
            cout << adj[i].size() << " ";
        }
    }else{
        cout << n << ' ' << cnt << endl;
        for(auto i : ans) cout << i.first << ' ' << i.second << endl;  
    }
}