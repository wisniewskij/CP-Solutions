// github.com/wisniewskij/Code
// cses.fi/problemset/task/1678
// Round Trip II
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

vector<vector<int>> G;
vector<int> vis, par;

int dfs(int v){
    vis[v]=2;
    for(auto x:G[v]){
        if(vis[x]==2){
            par[x]=v;
            return x;
        }
        else if(!vis[x]){
            par[x]=v;
            int z=dfs(x);
            if(z) return z;
        }
    }
    vis[v]=1;
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    G.assign(n+1, vector<int>());
    vis.assign(n+1, 0);
    par.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            int z=dfs(i);
            if(z){
                vector<int> path={};
                for(int j=par[z];j!=z;j=par[j]){
                    path.push_back(j);
                }
                reverse(all(path));
                cout<<path.size()+2<<ndl;
                cout<<z<<" ";
                for(auto x:path) cout<<x<<" ";
                cout<<z;
                return 0;
            }
        }
    cout<<"IMPOSSIBLE";
}