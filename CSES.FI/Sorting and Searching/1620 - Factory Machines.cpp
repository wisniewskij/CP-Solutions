// github.com/wisniewskij/Code
// cses.fi/problemset/task/1620
// Factory Machines

 
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

ll f(ll t, vector<ll> A){
    ll sum = 0;
    for(auto x:A) sum+=min(t/x, (ll)1e9);
    return sum;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, t;
    cin>>n>>t;
    vector<ll> A(n);
    for(auto &x:A) cin>>x;
    ll a=0, b=(ll)1e18;
    while(a+1<b){
        ll sr = (a+b)/2;
        if(f(sr, A)>=t) b=sr;
        else a=sr;
    }
    cout<<b<<ndl;
}