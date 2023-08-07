// github.com/wisniewskij/Code
// cses.fi/problemset/task/2416
// Increasing Array Queries
 
#include <bits/stdc++.h>
#define ndl '\n'
#define ll long long
#define INF 1e18
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

ll n,q;
ll bit[200002];
 
void update(int pos, ll val){
    for(;pos<=n;pos+=pos&-pos) bit[pos]+=val;
}
 
ll query(int a, int b){
    ll ans=0;
    for(;b;b-=b&-b) ans+=bit[b];
    for(a--;a;a-=a&-a) ans-=bit[a];
    return ans;
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin>>n>>q;
 
    vector<ll> pfx(n+2), x(n+2), contribution(n+2), ans(q);
 
    for(int i=1;i<=n;i++){
        cin>>x[i];
        pfx[i]=pfx[i-1]+x[i];
    }
    x[n+1]=INF;
    pfx[n+1]=pfx[n]+x[n+1];
 
    vector<vector<pair<int,int>>> queries(n+2);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        queries[a].push_back({b,i});
    }
 
    deque<ll> stack = {n+1};
 
    for(int i=n;i>0;i--){
        while(stack.size()&&x[i]>=x[stack.front()]){
            update(stack.front(), -contribution[stack.front()]);
            stack.pop_front();
        }
        contribution[i]=(stack.front()-i-1)*x[i]-(pfx[stack.front()-1]-pfx[i]);
        update(i, contribution[i]);
        stack.push_front(i);
        for(auto [a,b]:queries[i]){
            int pos = upper_bound(all(stack), a)-stack.begin()-1;
            ans[b]=(pos?query(i, stack[pos-1]):0) + (a - stack[pos])*x[stack[pos]]-(pfx[a]-pfx[stack[pos]]);
        }
    }
 
    for(int i=0;i<q;i++) cout<<ans[i]<<ndl;
    return 0;
}