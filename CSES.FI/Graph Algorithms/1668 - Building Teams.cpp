// github.com/wisniewskij/Code
// cses.fi/problemset/task/1668
// Building Teams

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
    vector<int> gr(n+1, 0);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!gr[i]){
            gr[i]=1;
            q.push(i);
            while(!q.empty()){
                int v=q.front();
                q.pop();
                for(auto x:G[v]){
                    if(!gr[x]){
                        gr[x]=(gr[v]==1?2:1);
                        q.push(x);
                    }
                    else if(gr[x]&&gr[v]==gr[x]){
                        cout<<"IMPOSSIBLE";
                        return 0;
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++)
        cout<<gr[i]<<" ";
}
