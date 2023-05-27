// github.com/wisniewskij/Code
// cses.fi/problemset/task/1693
// Teleporter Path
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
#define M (int)1e5+1
 
using namespace std;
 
vector<int> G[M], stck;
bool vis[M];
int in_d[M], ou_d[M], wzn[M];
 
void dfs(int v){
    vis[v]=1;
    while(wzn[v]<G[v].size()){
        dfs(G[v][wzn[v]++]);
    }
    stck.push_back(v);
}
 
int main(){
 
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) wzn[i]=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        in_d[b]++; ou_d[a]++;
        G[a].push_back(b);
    }
    G[n].push_back(1);
    ou_d[n]++; in_d[1]++;
    for(int i=1;i<=n;i++) if(in_d[i]!=ou_d[i]){
        cout<<"IMPOSSIBLE"; 
        return 0;
    }
 
    dfs(1);
    for(int i=1;i<=n;i++){
        if(wzn[i]!=G[i].size()){
            cout<<"IMPOSSIBLE";
            return 0;
        }}
 
    reverse(all(stck));
    stck.pop_back();
    int ind=0;
    for(int i=stck.size()-1;i>=0;i--){
        if(stck[i]==n){
            ind=i;
            break;
        }
    }
    for(int i=ind+1;i<stck.size();i++)
        cout<<stck[i]<<" ";
    for(int i=0;i<=ind;i++)
        cout<<stck[i]<<" ";
 
}