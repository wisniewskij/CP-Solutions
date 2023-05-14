// github.com/wisniewskij/Code
// cses.fi/problemset/task/1648
// Dynamic Range Sum Queries

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
    vector<ll> drq(n+1), t(n+1);
    for(ll i=1;i<=n;i++){
        cin>>t[i];
        for(ll j=i;j<=n;j+=(j&-j)) drq[j]+=t[i];
    }
    while(q--){
        ll l,a,b;
        cin>>l>>a>>b;
        if(l==1){
            for(int i=a; i<=n; i+=(i&-i)) drq[i]+=(b-t[a]);
            t[a]=b;
        }
        else{
            ll sum=0;
            for(int i=a-1;i>0;i-=(i&-i)) sum-=drq[i];
            for(int i=b;i>0;i-=(i&-i)) sum+=drq[i];
            cout<<sum<<ndl;
        }
    }
}