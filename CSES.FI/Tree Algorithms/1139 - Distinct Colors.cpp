// github.com/wisniewskij/Code
// cses.fi/problemset/task/1139
// Distinc Colors

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

void dfs(int v, int p, vector<vector<int>> &G, vector<map<int,int>> &mp, vector<int> &ans){
    for(auto x:G[v]){
        if(x==p) continue;
        dfs(x, v, G, mp, ans);
        if(mp[x].size()>mp[v].size()) swap(mp[x], mp[v]);
        mp[v].insert(all(mp[x]));
    }
    ans[v]=mp[v].size();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> G(n+1);
    vector<map<int,int>> mp(n+1);
    for(int i=1;i<=n;i++){
        int tmp; cin>>tmp;
        mp[i][tmp]=1;
    }
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> ans(n+1);
    dfs(1, 0, G, mp, ans);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}