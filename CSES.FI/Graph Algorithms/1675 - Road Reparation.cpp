// github.com/wisniewskij/Code
// cses.fi/problemset/task/1675
// Road Reparation
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

class DSU{
    vector<int> rep, rank;
    public:
    DSU(int m){
        rank.assign(m+1, 0);
        rep.assign(m+1, 0);
        for(int i=1;i<=m;i++)
            rep[i]=i;
    }
    int find(int v){
        if(rep[v]==v) return v;
        return rep[v]=find(rep[v]);
    }
    void uni(int v, int w){
        v=find(v);
        w=find(w);
        if(v==w) return;
        if(rank[v]<rank[w])
            rep[w]=v;
        else
            rep[v]=w;
        if(rank[w]==rank[v])
            rank[w]++;
    }
    bool in_union(int v, int w){
        return find(v)==find(w);
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; ll ans=0;
    cin>>n>>m;
    DSU dsu(n);
    vector<tuple<int, int, int>> E(m);
    for(auto &[c,a,b]:E)
        cin>>a>>b>>c;

    sort(all(E));
    
    for(auto [c,a,b]:E){
        if(!dsu.in_union(a,b)){
            dsu.uni(a,b);
            ans+=c;
        }
    }
    for(int i=2;i<=n;i++)
        if(!dsu.in_union(1, i)){
            cout<<"IMPOSSIBLE";
            return 0;
        }    
    cout<<ans;
}