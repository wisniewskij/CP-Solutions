// github.com/wisniewskij/Code
// cses.fi/problemset/task/1138
// Path Queries

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m, d=0;
vector<vector<int>> G;
vector<int> val, sz, idx;
vector<ll> bit, valsum;

void dfs(int v, int p, ll sumfromroot){
    idx[v]=++d;
    sumfromroot+=val[v];
    valsum[idx[v]]=sumfromroot;
    for(auto x:G[v])
        if(x!=p){
            dfs(x, v, sumfromroot);
            sz[v]+=sz[x]+1;
        }
}


void add(int x, ll val){
    for(int i=x;i<=n;i+=i&-i)
        bit[i]+=val;
}

ll get(int x){
    ll sum=0;
    for(int i=x;i>0;i-=i&-i)
        sum+=bit[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    G.assign(n+1, vector<int>());
    val.assign(n+1, 0); sz.assign(n+1, 0); valsum.assign(n+1, 0); idx.assign(n+1, 0), bit.assign(n+1, 0);

    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0, 0);

    for(int i=1;i<=n;i++)
        add(i, valsum[i]-valsum[i-1]);

    while(m--){
        int q;
        cin>>q;
        if(q==1){
            int s,x;
            cin>>s>>x;
            add(idx[s], x-val[s]);
            add(idx[s]+sz[s]+1, val[s]-x);
            val[s]=x;
        }
        else{
            int s;
            cin>>s;
            cout<<get(idx[s])<<ndl;
        }
    }






}