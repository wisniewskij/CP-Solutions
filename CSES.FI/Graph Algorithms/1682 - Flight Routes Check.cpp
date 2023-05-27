// github.com/wisniewskij/Code
// cses.fi/problemset/task/1682
// Flight Routes Check
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

vector<vector<int>> G, Gr;
vector<bool> vis;
vector<int> stck;

void dfs(int v){
    vis[v]=1;
    for(auto x:G[v])
        if(!vis[x]) dfs(x);
    stck.push_back(v);
}

void dfs2(int v){
    vis[v]=1;
    for(auto x:Gr[v])
        if(!vis[x]) dfs2(x);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    G.assign(n+1,vector<int>());
    Gr.assign(n+1,vector<int>());
    vis.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        Gr[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i);
    
    fill(all(vis), 0);
    dfs2(stck[n-1]);
    for(int i=0;i<n;i++){
        if(!vis[stck[i]]){
            cout<<"NO"<<ndl<<stck[i]<<" "<<stck[n-1];
            return 0;
        }
    }
    cout<<"YES";  
}