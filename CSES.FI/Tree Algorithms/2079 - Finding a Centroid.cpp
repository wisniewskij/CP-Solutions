// github.com/wisniewskij/Code
// cses.fi/problemset/task/2079
// Finding a Centroid

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5+1;
vector<int> G[N];
int sz[N], n;

void dfs(int v, int p){
    sz[v]++;
    for(auto x:G[v]){
        if(x==p) continue;
        dfs(x, v);
        sz[v]+=sz[x];
    }
}

int centroid(int v, int p){
    for(auto x:G[v]) if(x!=p && sz[x]>n/2) return centroid(x, v);
    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0);
    cout<<centroid(1, 0);
}