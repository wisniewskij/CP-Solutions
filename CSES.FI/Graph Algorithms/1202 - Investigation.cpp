// github.com/wisniewskij/Code
// cses.fi/problemset/task/1202
// Investigation
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define MOD ((ll)1e9+7)
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> G(n+1);
    vector<vector<int>> G2(n+1);
    vector<ll> dis(n+1, INF);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back({b,c});
    }
    vector<vector<ll>> ans(n+1, vector<ll>(4)); //dist, amount, min, max
    for(int i=1;i<=n;i++) ans[i]={INF, 0, INF, 0};
    ans[1]={0, 1, 0, 0};
    priority_queue<tuple<ll,int,int>> q;
    vector<int> stck, vis(n+1, 0);
    q.push({0, 1, 0});
    while(!q.empty()){
        auto [val, v, par]=q.top();
        q.pop();
        val=-val;
        if(ans[v][0]==val)
            G2[par].push_back(v);

        if(vis[v]) continue;
        vis[v]=1;
        stck.push_back(v);

        for(auto [x,y]:G[v]){
            if(ans[x][0]>=ans[v][0]+y){
                ans[x][0]=ans[v][0]+y;
                q.push({-ans[x][0], x, v});
            }
        }
    }
    for(auto i:stck)
        for(auto x:G2[i]){
            ans[x][1]=(ans[x][1]+ans[i][1])%MOD;
            ans[x][2]=min(ans[x][2], ans[i][2]+1);
            ans[x][3]=max(ans[x][3], ans[i][3]+1);
        }
    for(auto x:ans[n]) cout<<x<<" ";
}