// github.com/wisniewskij/Code
// cses.fi/problemset/task/1686
// Coin Collector
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
vector<vector<int>> G, Gr, Gc;
vector<int> tab, stck, vis;
vector<ll> coins_in_component;
 
void dfs(int v){
    vis[v]=1;
    for(auto x:G[v])
        if(!vis[x]) dfs(x);
    stck.push_back(v);
}
 
void dfs2(int v, int q){
    vis[v]=q;
    coins_in_component[q]+=tab[v];
 
    for(auto x:Gr[v]){
        if(vis[x]){
            if(vis[x]!=q)
                Gc[vis[x]].push_back(q);
        }
        else dfs2(x, q);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    G.assign(n+1, vector<int>()); Gr.assign(n+1, vector<int>()); vis.assign(n+1, 0); tab.assign(n+1, -1);
 
    for(int i=1;i<=n;i++) cin>>tab[i];
 
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        Gr[b].push_back(a);
    }
 
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    
    reverse(all(stck));
    vis.assign(n+1, 0);
    Gc.assign(1, vector<int>());
    coins_in_component.assign(1, 0);
    int num=1;
    for(auto x:stck)
        if(!vis[x]){
            coins_in_component.push_back(0);
            Gc.push_back(vector<int>());
            dfs2(x, num++);
        } 
    
    vector<ll> max_coins(num, 0);
    for(int i=1;i<num;i++)
        max_coins[i]=coins_in_component[i];
 
    ll ans=0;
    for(int i=1;i<num;i++){
        for(auto x:Gc[i]){
            max_coins[x]=max(max_coins[x], max_coins[i]+coins_in_component[x]);
        }
    }
    for(int i=1;i<num;i++){
        ans = max(ans, max_coins[i]);
    }
    cout<<ans;
}