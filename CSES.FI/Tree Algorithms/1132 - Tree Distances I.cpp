// github.com/wisniewskij/Code
// cses.fi/problemset/task/1132
// Tree Distances I

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
vector<pair<pair<int,int>, pair<int,int>>> dp;
vector<int> par;

void dfs(int n, int p){
    for(auto v : G[n]){
        if(v==p) continue;
        dfs(v, n);
        if(dp[v].st.st+1>dp[n].st.st){
            dp[n].nd=dp[n].st;
            dp[n].st={dp[v].st.st+1, v};
        }
        else if(dp[v].st.st+1>dp[n].nd.st) dp[n].nd={dp[v].st.st+1, v};
    }
}

void dfs2(int n, int p){
    if(p) par[n]=1+max(par[p], (dp[p].st.nd!=n?dp[p].st.st:dp[p].nd.st));
    for(auto v : G[n]){
        if(v==p) continue;
        dfs2(v, n);
    }
}

int main(){
    int n;
    cin>>n;
    G.assign(n + 1, vector<int>());
    dp.assign(n+1, {{0,0}, {0,0}});
    par.assign(n+1, 0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 0);

    for(int i=1;i<=n;i++)
        cout<<max(dp[i].st.st, par[i])<<" ";
}