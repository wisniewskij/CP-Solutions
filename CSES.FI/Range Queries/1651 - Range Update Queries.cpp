// github.com/wisniewskij/Code
// cses.fi/problemset/task/1651
// Range Update Queries

#include <bits/stdc++.h>
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<ll> drq(n+1), t(n+1), dt(n+1); //dynamic range query / tbl / difference tbl
    for(ll i=1;i<=n;i++){
        cin>>t[i];
        dt[i]=t[i]-t[i-1];
        for(ll j=i;j<=n;j+=(j&-j)) drq[j]+=dt[i];
    }
    while(q--){
        ll l,a,b,u;
        cin>>l;
        if(l==1){
            cin>>a>>b>>u;
            dt[a]+=u;
            if(b+1<=n) dt[b+1]-=u;
            for(int i=a;i<=n;i+=(i&-i)) drq[i]+=u;
            for(int i=b+1;i<=n;i+=(i&-i)) drq[i]-=u;
        }
        else{
            cin>>a;
            ll sum=0;
            for(int i=a;i>0;i-=(i&-i)) sum+=drq[i];
            cout<<sum<<ndl;
        }
    }
}