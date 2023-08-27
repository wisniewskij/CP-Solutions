// github.com/wisniewskij/Code
// cses.fi/problemset/task/2134
// Path Queries II

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

int maxLg, segTreeBase;
vector<int> val, sz, depth, chain, position, chainHead;
vector<vector<int>> G, par;

vector<ll> segTree;

void assignments(int n) {
    maxLg=__lg(n)+1;
    val.assign(n+1, 0);
    sz.assign(n+1, 0);
    depth.assign(n+1, 0);
    chain.assign(n+1, 0);
    position.assign(n+1, 0);
    chainHead.assign(n+1, 0);
    chainHead[0]=1;
    G.assign(n+1, vector<int>());
    par.assign(n+1, vector<int>(maxLg, 0));

    for(segTreeBase=1; segTreeBase<n; segTreeBase<<=1);
    segTree.assign(segTreeBase<<1, 0);
}

void setQ(int x, int val){
    x+=segTreeBase;
    segTree[x]=val;
    for(int i=x/2;i>0;i>>=1)
        segTree[i]=max(segTree[i*2], segTree[i*2+1]);
}

ll query(int a, int b){
    a+=segTreeBase; b+=segTreeBase;
    ll maxi = -1;
    while(a<=b){
        if(a&1) maxi=max(maxi, segTree[a++]);
        if((b&1)^1) maxi=max(maxi, segTree[b--]);
        a/=2; b/=2;
    }
    return maxi;
}

void dfs(int v, int p){
    par[v][0]=p;
    depth[v]=depth[p]+1;
    for(int i=1;i<maxLg;i++)
        if(par[v][i-1]!=0)
            par[v][i]=par[par[v][i-1]][i-1];

    sz[v]=1;
    for(auto x:G[v])
        if(x!=p){
            dfs(x, v);
            sz[v]+=sz[x];
        }
}

int lca(int a, int b){
    if(depth[a]>depth[b]) swap(a,b);
    int c=depth[b]-depth[a];
    for(int i=0; c>0; c>>=1, i++)
        if(c&1) b=par[b][i];

    if(a==b) return a;

    for(int i=maxLg-1;i>=0;i--)
        while(par[a][i]!=par[b][i]){
            a=par[a][i];
            b=par[b][i];
        }
    return par[a][0];
}

int chainId=0, pos=0;
void hld(int v, int p){
    int hV = -1, hSz = -1;

    chain[v]=chainId;
    setQ(pos, val[v]);
    position[v]=pos++;

    for(auto x:G[v]){
        if(x==p) continue;
        if(sz[x]>hSz){
            hSz=sz[x];
            hV=x;
        }
    }

    if(hV!=-1){
        hld(hV, v);
    }

    for(auto x:G[v]){
        if(x==p||x==hV) continue;
        chainId++;
        chainHead[chainId]=x;
        hld(x, v);
    }
}

ll hldQuery(int a, int b){
    int currLca = lca(a,b);
    ll maxi = -1;
    while(chain[a]!=chain[currLca]){
        maxi=max(maxi, query(position[chainHead[chain[a]]], position[a]));
        a=par[chainHead[chain[a]]][0];
    }
    maxi=max(maxi, query(position[currLca], position[a]));

    while(chain[b]!=chain[currLca]){
        maxi=max(maxi, query(position[chainHead[chain[b]]], position[b]));
        b=par[chainHead[chain[b]]][0];
    }
    maxi=max(maxi, query(position[currLca], position[b]));

    return maxi;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;

    assignments(n);

    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0);
    hld(1, 0);
    
    while(m--){
        int q; cin>>q;
        if(q==1){
            int s, x; cin>>s>>x;
            setQ(position[s], x);
        }
        else{
            int a, b; cin>>a>>b;
            cout<<hldQuery(a, b)<<" ";
        }
    }
}