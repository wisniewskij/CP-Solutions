// github.com/wisniewskij/Code
// cses.fi/problemset/task/1696
// School Dance
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()

using namespace std;
 
/*

****FLOW VERSION***
vector<vector<ll>> G, E;
vector<ll> vis, par;
 
bool dfs(int v, int k){
    if(v==k) return 1;
    vis[v]=1;
    for(int i=0;i<=k;i++){
        if(vis[i]||!G[v][i]||!E[v][i]) continue;
        par[i]=v;
        if(dfs(i, k)) return 1;
    }
    return 0;
}
 
bool run_dfs(int n, int m){
    vis.assign(n+m+2, 0);
    par.assign(n+m+2, -1);
    return dfs(0, n+m+1);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, k;
    cin>>n>>m>>k;
    G.assign(n+m+2, vector<ll>(n+m+2, 0));
    E.assign(n+m+2, vector<ll>(n+m+2, 0));
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        G[a][b+n]=1; G[b+n][a]=1; E[a][b+n]=1;
        G[0][a]=1; G[a][0]=1; E[0][a]=1;
        G[b+n][n+m+1]=1; G[n+m+1][b+n]=1; E[b+n][n+m+1]=1;
    }
    int sum=0;
    while(run_dfs(n, m)){
        for(int i=n+m+1; par[i]!=-1; i=par[i]){
            int j=par[i];
            E[j][i]-=1;
            E[i][j]+=1;
        }
        sum++;
    }
    cout<<sum<<ndl;
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=n+m;j++)
            if(G[i][j]&&E[i][j]==0)
                cout<<i<<" "<<j-n<<ndl;
}

*/

// Turbo-Pairing Version

vector<vector<int>> G;
vector<int> vis, paired_with;

bool try_pairing(int v){
    for(auto x:G[v]){
        if(vis[x]) continue;
        vis[x]=1;
        if(paired_with[x]==-1||try_pairing(paired_with[x])){
            paired_with[x]=v;
            return 1;
        }
    }
    return 0;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    G.assign(n+1, vector<int>());
    vis.assign(m+1, 0);
    paired_with.assign(m+1, -1);
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        fill(all(vis), 0);
        if(try_pairing(i)) sum++;
    }
    cout<<sum<<ndl;
    for(int i=1;i<=m;i++)
        if(paired_with[i]!=-1)
            cout<<paired_with[i]<<" "<<i<<ndl;
}