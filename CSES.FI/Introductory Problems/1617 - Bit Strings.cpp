// github.com/wisniewskij/Code
// cses.fi/problemset/task/1617
// Bit Strings

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
using namespace std;

ll fpow(ll p, ll w){
    if(w==0) return 1;
    ll ans = fpow(p, w/2);
    ans = (ans * ans)%mod;
    return (w&1?ans*p:ans)%mod;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    cout<<fpow(2, n);
}
