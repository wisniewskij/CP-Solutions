// github.com/wisniewskij/Code
// cses.fi/problemset/task/1632
// Maximum Subarray Sum II
 
 
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
    int n, a, b;
    cin>>n>>a>>b;
    vector<ll> t(n+1), pfx(n+1);
    multiset<ll> s;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        pfx[i]=pfx[i-1]+t[i];
    }
    ll maxi=pfx[a];
    for(int i=a;i<=n;i++){
        s.insert(pfx[i-a]);
        if(i>b)
            s.erase(s.find(pfx[i-b-1]));
        if(s.size()) maxi=max(maxi, pfx[i]-(*s.begin()));
    }
    cout<<maxi<<ndl;
}