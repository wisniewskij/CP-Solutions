// github.com/wisniewskij/Code
// cses.fi/problemset/task/1689
// Knight's Tour
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define N 8

using namespace std;
 
int vis[N][N];
int xx[]={1,1,-1,-1,2,2,-2,-2};
int yy[]={2,-2,2,-2,1,-1,1,-1};
 
int lr(int y, int x){
    if(y>=N||x>=N||y<0||x<0||vis[y][x]) return -1;
    int sum=0;
    for(int i=0;i<8;i++)
        if(x+xx[i]>=0&&x+xx[i]<N&&y+yy[i]>=0&&y+yy[i]<N&&!vis[y+yy[i]][x+xx[i]])
            sum++;
    return sum;
}
 
bool dfs(int y, int x, int sum){
    vis[y][x]=sum;
    if(sum==N*N) return 1;
    vector<pair<int,int>> v;
    for(int i=0;i<8;i++){
        int buf=lr(y+yy[i], x+xx[i]);
        if(buf>=0) v.push_back({buf, i});
    }
    sort(all(v));
    for(auto [b,i]:v)
        if(dfs(y+yy[i],x+xx[i],sum+1)) return 1;
 
    vis[y][x]=0;
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int y, x;
    cin>>x>>y;
    dfs(y-1, x-1, 1);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<vis[i][j]<<" ";
        cout<<ndl;
    }
}   