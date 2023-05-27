// github.com/wisniewskij/Code
// cses.fi/problemset/task/1691
// Mail Delivery
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

vector<int> stck;
bool E[(int)2e5+1];
vector<pair<int,int>> G[(int)1e5+1];
int wsk[(int)1e5+1];
 

void dfs(int v){
    for(wsk[v];wsk[v]<G[v].size();wsk[v]++){
        if(E[G[v][wsk[v]].nd]) continue;
        E[G[v][wsk[v]].nd]=1;
        dfs(G[v][wsk[v]].st);
    }
    stck.push_back(v);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    for(int i=1;i<=n;i++) if(G[i].size()%2){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    dfs(1);
    for(int i=0;i<m;i++) if(!E[i]){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(auto x:stck) cout<<x<<" ";
}
 