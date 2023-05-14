// github.com/wisniewskij/Code
// cses.fi/problemset/task/1646
// Static Range Sum Queries

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
    vector<ll> t(n), pfx(n+1);
    for(ll i=0;i<n;i++) cin>>t[i];
    for(ll i=1;i<=n;i++) pfx[i]=pfx[i-1]+t[i-1];
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<pfx[b]-pfx[a-1]<<ndl;
    }
 
}