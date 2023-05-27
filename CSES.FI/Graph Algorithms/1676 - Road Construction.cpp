// github.com/wisniewskij/Code
// cses.fi/problemset/task/1676
// Road Construction
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
    vector<int> rep, size;
    int max_size=0, comp;
    public:
    DSU(int m){
        rep.assign(m+1, 0);
        size.assign(m+1, 1);
        comp=m;
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
        if(size[v]>size[w]) swap(w,v);
        rep[w]=v;
        size[v]+=size[w];
        max_size=max(max_size, size[v]);
        comp--;
    }
    bool in_union(int v, int w){
        return find(v)==find(w);
    }
    int get_max_size(){
        return max_size;
    }
    int get_comp(){
        return comp;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        dsu.uni(a,b);
        cout<<dsu.get_comp()<<" "<<dsu.get_max_size()<<ndl;
    }
   
}