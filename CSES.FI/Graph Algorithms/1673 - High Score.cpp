// github.com/wisniewskij/Code
// cses.fi/problemset/task/1673
// High Score
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

void dfs(int v, vector<bool> &vis, vector<vector<int>> &G){
    vis[v]=1;
    for(auto x:G[v]){
        if(!vis[x]){
            dfs(x, vis, G);
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,ll>> E;
    vector<vector<int>> G(n+1), RG(n+1); //graph and reversed graph
    vector<ll> score(n+1, -INF);
    score[1]=0;
    for(int i=0;i<m;i++){
        int a,b; ll c;
        cin>>a>>b>>c;
        E.push_back({a,b,c});
        G[a].push_back(b);
        RG[b].push_back(a);
    }
    vector<bool> vis1(n+1,0), vis2(n+1,0);
    dfs(1, vis1, G);
    dfs(n, vis2, RG);


    vector<bool> mark(n+1, 0);
    for(int i=0;i<n;i++){
        for(auto [a,b,c]:E){
            if(score[b]<score[a]+c){
                score[b]=score[a]+c;
                if(i==n-1&&vis1[b]&&vis2[b]){
                    cout<<-1<<ndl;
                    return 0;
                }
            }
        }
    }
    cout<<score[n];
}