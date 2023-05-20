// github.com/wisniewskij/Code
// cses.fi/problemset/task/1194
// Monsters
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
    vector<string> t(n);
    for(int i=0;i<n;i++) cin>>t[i];
    
    vector<pair<int,int>> mons(1);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(t[i][j]=='A') mons[0]={i,j};
            else if(t[i][j]=='M') mons.push_back({i,j});
        }
        
    int x[]={0,1,0,-1}, y[]={1,0,-1,0};
    string d="DRUL";
    vector<vector<int>> dis(n, vector<int>(m, INF)), dis2(n, vector<int>(m, INF)), par(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    for(int i=1;i<mons.size();i++){
        dis[mons[i].st][mons[i].nd]=0;
        q.push(mons[i]);
    }
    
    while(!q.empty()){
        pair<int,int> v=q.front();
        q.pop();
        for(int i=0;i<4;i++)
            if(v.st+y[i]<n&&v.st+y[i]>=0&&v.nd+x[i]<m&&v.nd+x[i]>=0&&t[v.st+y[i]][v.nd+x[i]]!='#'&&dis[v.st+y[i]][v.nd+x[i]]>dis[v.st][v.nd]+1){
                dis[v.st+y[i]][v.nd+x[i]]=dis[v.st][v.nd]+1;
                q.push({v.st+y[i],v.nd+x[i]});
            }
    }

    dis2[mons[0].st][mons[0].nd]=0;
    q.push(mons[0]);
    pair<int,int> edge{-1,-1};
    
    while(!q.empty()){
        pair<int,int> v=q.front();
        q.pop();
        if(v.st==0||v.st==n-1||v.nd==0||v.nd==m-1){
            edge=v;
            break;
        }
        for(int i=0;i<4;i++)
            if(v.st+y[i]<n&&v.st+y[i]>=0&&v.nd+x[i]<m&&v.nd+x[i]>=0&&t[v.st+y[i]][v.nd+x[i]]!='#'&&dis2[v.st+y[i]][v.nd+x[i]]>dis2[v.st][v.nd]+1&&dis[v.st+y[i]][v.nd+x[i]]>dis2[v.st][v.nd]+1){
                dis2[v.st+y[i]][v.nd+x[i]]=dis2[v.st][v.nd]+1;
                par[v.st+y[i]][v.nd+x[i]]=i;
                q.push({v.st+y[i],v.nd+x[i]});
            }
    }

    if(edge==make_pair(-1,-1)) cout<<"NO";
    else{
        cout<<"YES"<<ndl;
        vector<int> stack;
        pair<int,int> tmp=edge;
        while(tmp!=mons[0]){
            stack.push_back(par[tmp.st][tmp.nd]);
            tmp={tmp.st-y[par[tmp.st][tmp.nd]], tmp.nd-x[par[tmp.st][tmp.nd]]};
        }
        cout<<stack.size()<<ndl;
        for(int i=stack.size()-1;i>=0;i--)
            cout<<d[stack[i]];
    }

}