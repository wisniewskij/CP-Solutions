// github.com/wisniewskij/Code
// cses.fi/problemset/task/1140
// Projects
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000001
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<tuple<int,int,int>> proj(n);
    for(auto &[a,b,c]:proj)
        cin>>a>>b>>c;
    sort(all(proj), [](tuple<int,int,int> a, tuple<int,int,int> b){return get<1>(a)<=get<1>(b);});
    map<int, ll> dp;
    dp[0]=0;
    ll ans=0;
    for(auto [a,b,c]:proj){
        auto it = dp.lower_bound(a);
        it--;
        ans=max(ans, c+it->nd);
        dp[b]=ans;
    }
    cout<<ans;
}

