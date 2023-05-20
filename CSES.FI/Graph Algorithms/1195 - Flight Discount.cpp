// github.com/wisniewskij/Code
// cses.fi/problemset/task/1195
// Flight Discount
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

void djikstra(vector<vector<pair<int,int>>> &G, int a, vector<ll> &dis){
    priority_queue<pair<ll, int>> q;
    q.push({0, a});
    dis[a]=0;
    while(!q.empty()){
        auto [val,v]=q.top();
        q.pop();
        val=-val;
        if(dis[v]<val) continue;
        for(auto x:G[v]){
            if(dis[x.st]>dis[v]+x.nd){
                dis[x.st]=dis[v]+x.nd;
                q.push({-dis[x.st],x.st});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> G(n+1), GI(n+1);
    vector<tuple<int, int, int>> E;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back({b, c});
        GI[b].push_back({a,c});
        E.push_back({a,b,c});
    }
    vector<ll> dis1(n+1, INF), dis2(n+1, INF);
    djikstra(G, 1, dis1);
    djikstra(GI, n, dis2);

    ll mini=INF;
    for(auto [a,b,c]:E)
        mini=min(mini, dis1[a]+dis2[b]+c/2);
    
    cout<<mini;
}