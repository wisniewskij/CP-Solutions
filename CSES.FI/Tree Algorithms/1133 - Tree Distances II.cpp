// github.com/wisniewskij/Code
// cses.fi/problemset/task/1133
// Tree Distances II

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<vector<int>> G;
vector<ll> sum, sum2, subtr;

void dfs(int n, int p){
    for(auto v : G[n]){
        if(v==p) continue;
        dfs(v, n);
        subtr[n]+=subtr[v]+1;
        sum[n]+=sum[v]+subtr[v]+1;
    }
}

void dfs2(int n, int p){
    if(p)
        sum[n]+=G.size()-2*subtr[n]+sum[p]-sum[n]-3;
    
    for(auto v : G[n]){
        if(v==p) continue;
        dfs2(v, n);
    }
}

int main(){
    int n;
    cin>>n;
    G.assign(n + 1, vector<int>());
    subtr.assign(n+1, 0);
    sum.assign(n+1, 0);
    sum2.assign(n+1, 0);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 0);

    for(int i=1;i<=n;i++){
        cout<<sum[i]<<" ";
    }
}