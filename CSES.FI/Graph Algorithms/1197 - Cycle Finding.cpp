// github.com/wisniewskij/Code
// cses.fi/problemset/task/1197
// Cycle Finding
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
    int n,m;
    cin>>n>>m;
    vector<int> par(n+1);
    vector<tuple<int,int,int>> E;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        E.push_back({a,b,c});
    }
    vector<ll> dis(n+1);
    int start=-1;
    for(int i=0;i<n;i++){
        for(auto [a,b,c]:E){
            if(dis[b]>dis[a]+c){
                par[b]=a;
                dis[b]=dis[a]+c;
                if(i==n-1){
                    start=b;
                }
            }
        }
    }
    if(start==-1){
        cout<<"NO";
        return 0;
    }

    for(int i=0;i<n;i++)
        start=par[start];
    
    vector<int> path={start};
    for(int i=par[start]; i!=start; i=par[i])
        path.push_back(i);
    
    path.push_back(start);
    reverse(all(path));
    cout<<"YES"<<ndl;
    for(auto x:path) cout<<x<<" ";
}