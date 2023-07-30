// github.com/wisniewskij/Code
// cses.fi/problemset/task/1625
// Grid Paths

#include <bits/stdc++.h>
 
#define ndl '\n'
 
using namespace std;
 
vector<vector<bool>> vis(7, vector<bool>(7, 0));
int ans=0, wymiar=7;
 
string s;
 
void back_track(int r, int c, int dis){
    vis[r][c]=1;
    
    if(dis==wymiar*wymiar-1||(r==wymiar-1&&c==0))
        ans+=(dis==(wymiar*wymiar-1)&&(r==wymiar-1&&c==0));
    else{
        if((s[dis]=='?'||s[dis]=='D')&&r+1<wymiar&&!vis[r+1][c]&&!(c-1>=0&&c+1<wymiar&&(r+1==wymiar-1||vis[r+2][c])&&!vis[r+1][c-1]&&!vis[r+1][c+1]))
            back_track(r+1, c, dis+1);
        if((s[dis]=='?'||s[dis]=='U')&&r-1>=0&&!vis[r-1][c]&&!(c-1>=0&&c+1<wymiar&&(r-1==0||vis[r-2][c])&&!vis[r-1][c-1]&&!vis[r-1][c+1]))
            back_track(r-1, c, dis+1);
        if((s[dis]=='?'||s[dis]=='R')&&c+1<wymiar&&!vis[r][c+1]&&!(r-1>=0&&r+1<wymiar&&(c+1==wymiar-1||vis[r][c+2])&&!vis[r+1][c+1]&&!vis[r-1][c+1]))
            back_track(r, c+1, dis+1);
        if((s[dis]=='?'||s[dis]=='L')&&c-1>=0&&!vis[r][c-1]&&!(r-1>=0&&r+1<wymiar&&(c-1==0||vis[r][c-2])&&!vis[r+1][c-1]&&!vis[r-1][c-1]))
            back_track(r, c-1, dis+1);
    }
 
    vis[r][c]=0;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    back_track(0,0,0);
    cout<<ans;
}