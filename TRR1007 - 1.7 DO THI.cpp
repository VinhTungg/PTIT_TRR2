#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t, n;

int main(){
    boost;
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    fin >> t >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; ++i){
        int k;
        fin >> k;
        while(k--){
            int v;
            fin >> v;
            adj[i].push_back(v);
        }
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i){
            fout << adj[i].size();
            if(i != n) fout << " ";
        }
    }else{
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int v : adj[i]) {
                mat[i][v] = 1;
            }
        }
        fout << n << endl;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                fout << mat[i][j];
                if(j != n) fout << " ";
            }
            fout << endl;
        }
    }
}
