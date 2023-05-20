// github.com/wisniewskij/Code
// cses.fi/problemset/task/1669
// Round Trip
#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<vector<int>> G;
vector<int> par, vis;

int dfs(int v, int p){
    vis[v]=1;
    for(auto x:G[v]){
        if(x==p) continue;
        par[x]=v;
        if(vis[x]){
            return x;
        }
        else if(!vis[x]){
            int z=dfs(x, v);
            if(z!=-1) return z;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    G.assign(n+1, vector<int>());
    par.assign(n+1, -1);
    vis.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int z = dfs(i, -1);
            if(z!=-1){
                // cout<<z<<ndl<<par[z]<<par[5]<<par[3];
                vector<int> stack={z};
                for(int i=par[z];i!=z;i=par[i]){
                    stack.push_back(i);
                }
                stack.push_back(z);
                cout<<stack.size()<<ndl;
                for(auto x:stack)
                    cout<<x<<" ";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";

}