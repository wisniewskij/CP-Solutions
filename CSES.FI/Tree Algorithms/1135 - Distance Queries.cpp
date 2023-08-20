// github.com/wisniewskij/Code
// cses.fi/problemset/task/1135
// Distance Queries

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    cin>>n>>q;
    vector<vector<int>> G(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<int>> up(n+1, vector<int>(__lg(n)+1));
    vector<int> depth(n+1);

    queue<pair<int,int>> que;
    vector<bool> vis(n+1);
    que.push({1,0});

    while(!que.empty()){
        auto [v, p] = que.front();
        que.pop();
        for(auto x:G[v]){
            if(x!=p&&!vis[x]){
                que.push({x,v});
                up[x][0]=v;
                vis[x]=1;
                depth[x]=depth[v]+1;
            }
        }
    }

    for(int j=1;j<=__lg(n);j++)
        for(int i=2;i<=n;i++)
            up[i][j]=up[up[i][j-1]][j-1];
        

    while(q--){
        int a, b;
        cin>>a>>b;

        if(depth[a]>depth[b]) swap(a,b);

        int sum, c;
        sum=c=depth[b]-depth[a];

        for(int i=0;c>0;i++, c>>=1)
            if(c&1) b=up[b][i];

        if(a==b){
            cout<<sum<<ndl;
            continue;
        }

        for(int i=__lg(n);i>=0;i--)
            while(up[a][i]!=up[b][i]){
                a=up[a][i];
                b=up[b][i];
                sum+=1<<(i+1);
            }  

        cout<<sum+2<<ndl;
    }

}