// github.com/wisniewskij/Code
// cses.fi/problemset/task/1667
// Message Route
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> par(n+1, -1), dis(n+1, 0);
    queue<int> q;
    par[1]=-2;
    q.push(1);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto x:G[v]){
            if(par[x]==-1){
                par[x]=v;
                dis[x]=dis[v]+1;
                q.push(x);
            }
        }
    }
    if(dis[n]==0) cout<<"IMPOSSIBLE";
    else{
        cout<<dis[n]+1<<ndl;
        vector<int> stack;
        for(int i=n;i!=-2;i=par[i])
            stack.push_back(i);
        reverse(all(stack));
        for(auto x:stack) cout<<x<<" ";

    }
}