// github.com/wisniewskij/Code
// cses.fi/problemset/task/1684
// Giant Pizza
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int n,m;
vector<vector<int>> G, Gr;
vector<int> stck, comp, toping, vis;

void dfs(int v){
    vis[v]=1;
    for(auto x:G[v])
        if(!vis[x]) dfs(x);
    stck.push_back(v);
}

void dfs2(int v, int q){
    comp[v]=q;
    vis[v]=2;
    for(auto x:Gr[v])
        if(vis[x]!=2) dfs2(x, q);
}

void dfs3(int v){
    if(!toping[(v>m?v-m:v)]){
        toping[(v>m?v-m:v)]=(v>m?1:-1);
    }
    vis[v]=3;
    for(auto x:G[v])
        if(vis[x]!=3) dfs3(x);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    G.assign(2*m+1,vector<int>());
    Gr.assign(2*m+1,vector<int>());
    vis.assign(2*m+1, 0);
    comp.assign(2*m+1, 0);
    toping.assign(m+1, 0);
    for(int i=0;i<n;i++){
        char c1,c2; int i1,i2;
        cin>>c1>>i1>>c2>>i2;
        if(c1=='-'){
            G[i1+m].push_back((c2=='+'?i2+m:i2));
            Gr[(c2=='+'?i2+m:i2)].push_back(i1+m);
        }
        else{
            G[i1].push_back((c2=='+'?i2+m:i2));
            Gr[(c2=='+'?i2+m:i2)].push_back(i1);
        }
        if(c2=='-'){
            G[i2+m].push_back((c1=='+'?i1+m:i1));
            Gr[(c1=='+'?i1+m:i1)].push_back(i2+m);
        }
        else{
            G[i2].push_back((c1=='+'?i1+m:i1));
            Gr[(c1=='+'?i1+m:i1)].push_back(i2);
        }
    }

    for(int i=1;i<=m*2;i++)
        if(!vis[i]) dfs(i);
    
    reverse(all(stck));
    vector<int> stck2;
    int num=0;
    for(auto x:stck)
        if(vis[x]!=2){
            dfs2(x, ++num);
            stck2.push_back(x);
        } 
    
    for(int i=1;i<=m;i++)
        if(comp[i]==comp[i+m]&&comp[i]){
            cout<<"IMPOSSIBLE"<<ndl;
            return 0;
        }
    
    reverse(all(stck2));
    for(auto x:stck2)
        if(vis[x]!=3) dfs3(x);
        
    for(int i=1;i<=m;i++)
        cout<<(toping[i]==1?'+':'-')<<" ";    
}