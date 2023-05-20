// github.com/wisniewskij/Code
// cses.fi/problemset/task/1690
// Longest Flight Route
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
vector<int> vis, stck;

void dfs(int v){
    vis[v]=1;
    for(auto x:G[v]){
        if(!vis[x]){
            dfs(x);
        }
    }
    stck.push_back(v);
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
    }
    dfs(1);
    if(!vis[n]){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    reverse(all(stck));
    vector<int> dp(n+1), par(n+1);
    dp[1]=1; par[1]=-1; bool fl=0;
    for(auto i:stck){
        if(i==1) fl=1;
        if(fl) 
            for(auto x:G[i])
                if(dp[x]<dp[i]+1){
                    dp[x]=dp[i]+1;
                    par[x]=i;
                }
    }
    cout<<dp[n]<<ndl;
    stck.clear();
    for(int i=n; i!=-1; i=par[i])
        stck.push_back(i);
    reverse(all(stck));
    for(auto x:stck)
        cout<<x<<" ";
}