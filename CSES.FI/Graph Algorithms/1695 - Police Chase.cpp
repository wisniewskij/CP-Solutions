// github.com/wisniewskij/Code
// cses.fi/problemset/task/1695
// Police Chase
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
 
int n,m;
vector<vector<int>> G, E;
vector<int> vis; 
vector<int> par;
 
void dfs3(int v){
    vis[v]=2;
    for(auto x:G[v]){
        if(vis[x]==2) continue;
        if(vis[x]==1) dfs3(x);
        else{
            cout<<v<<" "<<x<<ndl;
        }
    }
}
 
void dfs2(int v){
    vis[v]=1;
    for(auto x:G[v]){
        if(vis[x]||E[v][x]==0) continue;
        dfs2(x);
    }
}
 
bool dfs(int v){
    if(n==v) return 1;
    vis[v]=1;
    for(auto x:G[v]){
        if(vis[x]||!E[v][x]) continue;
        par[x]=v;
        if(dfs(x)) return 1;
    }
    return 0;
}
 
bool run_dfs(){
    vis.assign(n+1, 0);
    par.assign(n+1, -1);
    return dfs(1);
}
 
void run_dfs2(){
    vis.assign(n+1, 0);
    dfs2(1);
    dfs3(1);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    G.assign(n+1, vector<int>());
    E.assign(n+1, vector<int>(n+1, 0));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        E[a][b]+=1;
        E[b][a]+=1;
    }
    int sum=0;
    while(run_dfs()){
        sum++;
        for(int i=n,j=par[n];j!=-1;i=par[i], j=par[j]){
            E[j][i]-=1;
            E[i][j]+=1;
        }
    }
    cout<<sum<<ndl;
    run_dfs2();
}