// github.com/wisniewskij/Code
// cses.fi/problemset/task/1662
// Subarray Divisibility

 
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
    int n, pfx=0;
    ll ans=0;
    cin>>n;
    map<ll, ll> m;
    m[0]=1;
    for(int i=0;i<n;i++){
        ll tmp;
        cin>>tmp;
        pfx=(pfx+tmp)%n;
        while(pfx<0) pfx+=n;
        ans+=m[pfx];
        m[pfx]++;
    }

    cout<<ans;
}