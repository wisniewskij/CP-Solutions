// github.com/wisniewskij/Code
// cses.fi/problemset/task/1652
// Forest Queries

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
    int n,q;
    cin>>n>>q;
    vector<vector<int>> t(n+1, vector<int>(n+1));
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=n;j++){
            t[i][j]=t[i-1][j]+t[i][j-1]-t[i-1][j-1]+(s[j-1]=='*'?1:0);
        }
    }
    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<t[y2][x2]-t[y1-1][x2]-t[y2][x1-1]+t[y1-1][x1-1]<<ndl;
    }
}