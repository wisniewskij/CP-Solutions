// github.com/wisniewskij/Code
// cses.fi/problemset/task/1085
// Array Division

 
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

ll f(ll x, vector<int> T){
    ll l=1, akt = 0;
    for(auto t:T){
        if(t>x) return LLONG_MAX;
        if(t+akt>x){
            l++;
            akt=t;
        }
        else
            akt+=t;
    }
    return l;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vector<int> t(n);
    for(auto &x:t) cin>>x;
    ll a = 0, b = (ll)1e16;
    while(a+1<b){
        ll sr = (a+b)/2;
        if(f(sr, t)>k) a=sr;
        else b=sr;
    }
    cout<<b<<ndl;
}