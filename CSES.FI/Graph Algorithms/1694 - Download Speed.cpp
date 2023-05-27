// github.com/wisniewskij/Code
// cses.fi/problemset/task/1694
// Download Speed
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define N 8

using namespace std;
 
vector<vector<ll>> G, E;
vector<ll> vis, par;
 
bool dfs(ll v, ll c, ll n){
    if(v==n) return 1;
    vis[v]=1;
    for(ll i=1;i<=n;i++){
        if(vis[i]||!G[v][i]||E[v][i]<c) continue;
        par[i]=v;
        if (dfs(i,c,n)) return 1;
    }
    return 0;
}
 
bool run_dfs(ll c, ll n){
    vis.assign(n+1, 0);
    par.assign(n+1, -1);
    return dfs(1, c, n);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin>>n>>m;
    G.assign(n+1, vector<ll>(n+1));
    E.assign(n+1, vector<ll>(n+1));
    ll maxi=0;
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        G[a][b]=1;
        G[b][a]=1;
        E[a][b]+=c;
        maxi=max(maxi, c);
    }
    ll p=1; while((p<<1)<=maxi) p<<=1;
    ll sum=0;
    for(ll i=p; i>0; i>>=1){
        while(run_dfs(i, n))
        {
            ll mini=maxi;
            for(ll j=n;par[j]!=-1;j=par[j]){
                ll k=par[j];
                mini=min(mini, E[k][j]);
            }
            sum+=mini;
            for(ll j=n;par[j]!=-1;j=par[j]){
                ll k=par[j];
                E[k][j]-=mini;
                E[j][k]+=mini;
            }
        }
    }
    cout<<sum;
 
}