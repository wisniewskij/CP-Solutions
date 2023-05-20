// github.com/wisniewskij/Code
// cses.fi/problemset/task/1192
// Counting Rooms
#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()

using namespace std;

int xa[]={0,1,0,-1}, ya[]={1,0,-1,0};

void dfs(int y, int x, int n, int m, vector<string> &s){
    s[y][x]='#';
    for(int i=0;i<4;i++)
        if(x+xa[i]>=0&&x+xa[i]<m&&y+ya[i]<n&&y+ya[i]>=0&&s[y+ya[i]][x+xa[i]]=='.')
            dfs(y+ya[i],x+xa[i],n,m,s);
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> t(n);
    for(int i=0;i<n;i++) cin>>t[i];
    int counter=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(t[i][j]=='.') {
                dfs(i,j,n,m,t);
                counter++;
            }
        }
    cout<<counter;
}