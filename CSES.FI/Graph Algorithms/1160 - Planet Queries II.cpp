// github.com/wisniewskij/Code
// cses.fi/problemset/task/1160
// Planet Queries II
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

vector<vector<int>> up;
vector<int> dis, vis;

void dfs(int v){
    if(vis[v]) return;
    vis[v]=1;
    dfs(up[v][0]);
    dis[v]=dis[up[v][0]]+1;
}

int jump(int a, int b){
    for(int i=0;b>0;i++,b>>=1){
        if(b&1) a=up[a][i];
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;

    up.assign(n+1, vector<int>(20));
    dis.assign(n+1, 0);
    vis.assign(n+1, 0);

    for(int j=0;j<20;j++)
        for(int i=1;i<=n;i++){
            if(j==0) cin>>up[i][0];
            else up[i][j]=up[up[i][j-1]][j-1];
        }

    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i);

    while(q--){
            int a, b, cycle_len;
            cin>>a>>b;
            cycle_len=dis[jump(a, dis[a])];
            if(dis[a]>=dis[b]&&jump(a, dis[a]-dis[b])==b)
                cout<<dis[a]-dis[b]<<ndl;
            else if(jump(a, dis[a]+cycle_len-dis[b])==b)
                cout<<dis[a]+cycle_len-dis[b]<<ndl;
            else cout<<-1<<ndl;
        }
}