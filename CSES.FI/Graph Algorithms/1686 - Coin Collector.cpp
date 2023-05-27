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

vector<vector<int>> G, G_reversed, G_component;
vector<int> coins_in_vertex, topo_stack, vis;
vector<ll> coins_in_component;

void dfs(int v){
    vis[v]=1;
    for(auto x:G[v])
        if(!vis[x]) dfs(x);
    topo_stack.push_back(v);
}

void dfs2(int v, int q){
    vis[v]=q;
    coins_in_component[q]+=coins_in_vertex[v];

    for(auto x:G_reversed[v]){
        if(vis[x]){
            if(vis[x]!=q)
                G_component[vis[x]].push_back(q);
        }
        else dfs2(x, q);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    G.assign(n+1, vector<int>()); G_reversed.assign(n+1, vector<int>()); vis.assign(n+1, 0); coins_in_vertex.assign(n+1, -1);

    for(int i=1;i<=n;i++) cin>>coins_in_vertex[i];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G_reversed[b].push_back(a);
    }

    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    
    reverse(all(topo_stack));

    vis.assign(n+1, 0);
    G_component.assign(1, vector<int>());
    coins_in_component.assign(1, 0);
    int num=1;

    for(auto x:topo_stack)
        if(!vis[x]){
            coins_in_component.push_back(0);
            G_component.push_back(vector<int>());
            dfs2(x, num++);
        } 
    
    vector<ll> max_coins_in_component(num, 0);
    for(int i=1;i<num;i++)
        max_coins_in_component[i]=coins_in_component[i];

    ll ans=0;
    for(int i=1;i<num;i++){
        for(auto x:G_component[i]){
            max_coins_in_component[x]=max(max_coins_in_component[x], max_coins_in_component[i]+coins_in_component[x]);
            ans=max(ans, max_coins_in_component[x]);
        }
    }
    cout<<ans;
}