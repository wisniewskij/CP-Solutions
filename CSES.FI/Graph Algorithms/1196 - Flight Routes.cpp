// github.com/wisniewskij/Code
// cses.fi/problemset/task/1196
// Flight Routes
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>>G(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back({b,c});
    }
    vector<ll> counter(n+1, k);
    priority_queue<pair<ll, int>> q;
    q.push({0, 1});
    vector<ll> distances;

    while(!q.empty()){
        auto [val, v]=q.top();
        q.pop();
        val=-val;

        if(!counter[v]) continue;
        counter[v]-=1;

        if(v==n)
            distances.push_back(val);

        for(auto x:G[v])
            q.push({-(x.nd+val), x.st});
    }

    for(auto x:distances)
        cout<<x<<" ";
}