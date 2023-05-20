// github.com/wisniewskij/Code
// cses.fi/problemset/task/1672
// Shortest Routes II
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> G(n+1, vector<ll>(n+1, INF));
    for(int i=1;i<=n;i++)
        G[i][i]=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a][b]=min((ll)c,G[a][b]);
        G[b][a]=min((ll)c,G[b][a]);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
    
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(G[a][b]!=INF?G[a][b]:-1)<<ndl;
    }

}