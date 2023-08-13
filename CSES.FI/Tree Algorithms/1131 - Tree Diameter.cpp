// github.com/wisniewskij/Code
// cses.fi/problemset/task/1131
// Tree Diameter

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

pair<int,int> dfs(int n, int p, int dis){
    pair<int,int> max_dis = {dis, n};           
    for (auto v : G[n]){
        if(v==p) continue;
        max_dis=max(max_dis, dfs(v, n, dis+1));
    }

    return max_dis;
}

int main(){
    int n;
    cin>>n;
    G.assign(n + 1, vector<int>());
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    pair<int,int> max_dis=dfs(1,-1,0);
    cout<<dfs(max_dis.nd, -1, 0).st;

    
}