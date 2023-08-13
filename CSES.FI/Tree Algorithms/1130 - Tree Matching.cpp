// github.com/wisniewskij/Code
// cses.fi/problemset/task/1130
// Tree Matching

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<vector<int>> G;
vector<int> w, o; //with / without

void dfs(int n, int p){
    int sum = 0;               
    for (auto v : G[n]){
        if(v==p) continue;
        dfs(v, n);
        o[n]+=max(w[v], o[v]);
    }

    for(auto v:G[n]){
        if(v==p) continue;
        w[n]=max(w[n], o[n]-max(w[v], o[v])+o[v]+1);
    }
}

int main(){
    int n;
    cin>>n;
    G.assign(n + 1, vector<int>());
    w.assign(n+1, 0);
    o.assign(n+1, 0);

    for (int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, -1);
    cout<<max(w[1], o[1]);
}