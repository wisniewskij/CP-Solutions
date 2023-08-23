// github.com/wisniewskij/Code
// cses.fi/problemset/task/1136
// Counting Paths

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

void dfs(int v, int p, vector<int> &val, vector<vector<int>> &G){
    for(auto x:G[v])
        if(x!=p){
            dfs(x, v, val, G);
            val[v]+=val[x];
        }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> G(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<int>> up(n+1, vector<int>(__lg(n)+1));
    vector<int> depth(n+1);

    queue<pair<int,int>> que; que.push({1,0});

    while(!que.empty()){
        auto [v, p] = que.front();
        que.pop();

        for(auto x:G[v]){
            if(x!=p){
                up[x][0]=v;
                depth[x]=depth[v]+1;
                que.push({x, v});
            }
        }
    }
    for(int j=1;j<=__lg(n);j++)
        for(int i=2;i<=n;i++)
            up[i][j]=up[up[i][j-1]][j-1];

    vector<int> val(n+1);

    while(m--){
        int a, b;
        cin>>a>>b;

        val[a]++;
        val[b]++;

        if(depth[b]<depth[a]) swap(a,b);

        int c = depth[b]-depth[a];
        for(int i=0;c>0;i++,c>>=1)
            if(c&1) b=up[b][i];

        if(a==b){
            val[a]--;
            if(up[a][0]) val[up[a][0]]--;
        }
        else{
            for(int i=__lg(n);i>=0;i--)
                while(up[a][i]!=up[b][i]){
                    a=up[a][i];
                    b=up[b][i];
                }
            a=up[a][0];
            val[a]--;
            if(up[a][0]) val[up[a][0]]--;
        }
    }


    dfs(1, 0, val, G);
    for(int i=1;i<=n;i++)
        cout<<val[i]<<" ";
}