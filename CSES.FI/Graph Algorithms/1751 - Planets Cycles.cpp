// github.com/wisniewskij/Code
// cses.fi/problemset/task/1751
// Planets Cycles
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
vector<int> dis, vis, cyc, cyc_len;
int z=0;

int dfs(int v){
    if(vis[v]==2){
        cyc_len[z]=0;
        cyc[v]=z++;
        return v;
    } 
    else if(vis[v]){
        return -1;
    }
    vis[v]=2;
    int wyn=dfs(up[v][0]);
    
    cyc[v]=cyc[up[v][0]];

    if(wyn==-1) 
        dis[v]=dis[up[v][0]]+1;
    else {
        dis[v]=0;
        cyc_len[cyc[v]]++;
    }

    vis[v]=1;
    if(v==wyn) return -1;
    return wyn;
}

int jump(int a, int b){
    for(int i=0;b>0;i++,b>>=1){
        if(b&1) a=up[a][i];
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;

    up.assign(n+1, vector<int>(20));
    dis.assign(n+1, 0);
    vis.assign(n+1, 0);
    cyc.assign(n+1, -1);
    cyc_len.assign(n+1, -1);

    for(int j=0;j<20;j++)
        for(int i=1;i<=n;i++){
            if(j==0) cin>>up[i][0];
            else up[i][j]=up[up[i][j-1]][j-1];
        }

    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i);
    
    for(int i=1;i<=n;i++)
        cout<<dis[i]+cyc_len[cyc[i]]<<" ";

    
}