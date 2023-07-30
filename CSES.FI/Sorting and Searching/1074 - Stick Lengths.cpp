// github.com/wisniewskij/Code
// cses.fi/problemset/task/1074
// Stick Lengths

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
    int n;
    cin>>n;
    vector<int> t(n);
    for(auto &x:t) cin>>x;
    sort(all(t));
    ll ans = 0;
    for(int i=0;i<n;i++)
        ans+=abs(t[i]-t[n/2]);
    cout<<ans;
}
