// github.com/wisniewskij/Code
// cses.fi/problemset/task/1671
// Shortest Routes I
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e16)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>> G(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        G[a].push_back({b,c});
    }

    vector<ll> dis(n+1, INF); 
    dis[1]=0;
    priority_queue<pair<ll,int>> q; 
    q.push({0,1});

    while(!q.empty()){
        int v; ll val;
        val=-q.top().st; v=q.top().nd;
        q.pop();
        if(dis[v]<val) continue;
        for(auto x:G[v]){
            if(dis[x.st]>val+x.nd){
                dis[x.st]=val+x.nd;
                q.push({-dis[x.st], x.st});
            }
        }
    }
    
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
}