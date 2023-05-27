// github.com/wisniewskij/Code
// cses.fi/problemset/task/1711
// Distinct Routes
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()

using namespace std;
 
vector<vector<int>> G, E, K;
vector<int> vis, par, vol;
 
bool dfs(int v, int n){
    if(v==n) return 1;
    vis[v]=1;
    for(auto x:G[v]){
        if(vis[x]||!E[v][x]) continue;
        par[x]=v;
        if(dfs(x, n)) return 1; 
    }
    return 0;
}
 
bool run_dfs(int n){
    vis.assign(n+1, 0);
    par.assign(n+1, -1);
    return dfs(1, n);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    G.assign(n+1, vector<int>());
    E.assign(n+1, vector<int>(n+1, 0));
    K.assign(n+1, vector<int>(n+1, 0));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        K[a][b]=1;
        E[a][b]+=1;
    }
    int sum=0;
    while(run_dfs(n)){
        for(int j=n; par[j]!=-1; j=par[j]){
            int i=par[j];
            E[i][j]-=1;
            E[j][i]+=1;
        }
        sum++;
    }
    cout<<sum<<ndl;
    
    vector<int> od(n+1, 0);
    while(sum--){
        vector<int> vec={1};
        int v=1;
        while(v!=n){
            for(auto x:G[v]){
                if(!E[v][x]&&K[v][x]){
                    E[v][x]++;
                    v=x;
                    vec.push_back(v);
                    break;
                }
            }
        }
        cout<<vec.size()<<ndl;
        for(auto x:vec) cout<<x<<" ";
        cout<<ndl;
    }
}  