// github.com/wisniewskij/Code
// cses.fi/problemset/task/1666
// Building Roads
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
vector<bool> vis;

void dfs(int v){
    vis[v]=1;
    for(auto x:G[v])
        if(!vis[x]) dfs(x);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    G.assign(n+1, vector<int>());
    vis.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<pair<int,int>> to_be_built;    

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            if(i!=1)
                to_be_built.push_back({i-1, i});
        }
    }
    cout<<to_be_built.size()<<ndl;
    for(auto [x,y]:to_be_built)
        cout<<x<<" "<<y<<ndl;
}