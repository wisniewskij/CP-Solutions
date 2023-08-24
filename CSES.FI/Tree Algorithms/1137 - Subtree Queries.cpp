// github.com/wisniewskij/Code
// cses.fi/problemset/task/1137
// Subtree Queries

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m;

vector<int> val, sz, idx;
vector<vector<int>> G;

int d=0;

void dfs(int v, int p){
    idx[v]=++d;
    for(auto x:G[v]){
        if(x==p) continue;
        dfs(x, v);
        sz[v]+=sz[x]+1;
    }
}

vector<ll> bit;

void add(int x, int val){
    for(int i=x;i<=n;i+=(i&-i))
        bit[i]+=val;
}

ll get(int a, int b){
    ll sum = 0;
    for(int i=b;i>0;i-=(i&-i)) sum+=bit[i];
    for(int i=a-1;i>0;i-=(i&-i)) sum-=bit[i];
    return sum;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    val.assign(n+1, 0);
    sz.assign(n+1, 0);
    idx.assign(n+1, 0);
    G.assign(n+1, vector<int>());
    bit.assign(n+1, 0);

    for(int i=1;i<=n;i++)
        cin>>val[i];

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0);

    for(int i=1;i<=n;i++)
        add(idx[i], val[i]);


    while(m--){
        int q;
        cin>>q;
        if(q==1){
            int a, b;
            cin>>a>>b;
            add(idx[a], b-val[a]);
            val[a]=b;
        }
        else{
            int a;
            cin>>a;
            cout<<get(idx[a], idx[a]+sz[a])<<ndl;
        }
    }

}