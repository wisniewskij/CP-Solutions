// github.com/wisniewskij/Code
// cses.fi/problemset/task/1679
// Course Schedule
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

bool dfs(int v){
    vis[v]=2;
    for(auto x:G[v]){
        if(vis[x]==2)
            return 1;
        else if(!vis[x]){
            if(dfs(x)) return 1;
        }
    }
    vis[v]=1;
    stck.push_back(v);
    return 0;
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
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i)){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    reverse(all(stck));
    for(auto x:stck) cout<<x<<" ";
}