// github.com/wisniewskij/Code
// cses.fi/problemset/task/1692
// De Bruijn Sequence
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;
vector<vector<pair<int,int>>> G;
vector<int> E;
vector<string> stck;
 
void dfs(int v, string kr){
    for(int i=0;i<2;i++){
        if(E[G[v][i].nd]) continue;
        E[G[v][i].nd]=1;
        dfs(G[v][i].st, (i?"1":"0"));
    }
    stck.push_back(kr);
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    if(n==1){
        cout<<"01";
        return 0;
    }
    G.assign((1<<(n-1)), vector<pair<int,int>>());
    E.assign((1<<n), 0);
    for(int i=0;i<(1<<(n-1));i++){
        G[i].push_back({(i<<1)%(1<<(n-1)), i});
        G[i].push_back({(i<<1)%(1<<(n-1))+1, (1<<(n-1))+i});
    }
    string s="";
    for(int i=0;i<n-1;i++)
        s+='0';
    dfs(0, s);   
    reverse(all(stck));
    for(auto x:stck) cout<<x;
 
}