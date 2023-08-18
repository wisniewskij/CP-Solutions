// github.com/wisniewskij/Code
// cses.fi/problemset/task/1687
// Company Queries I

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
    int n, q, m;
    cin>>n>>q;

    m = __lg(n);
    vector<vector<int>> boss(m+1, vector<int>(n+1));
    for(int i=0;i<=m;i++)
        for(int j=2;j<=n;j++){
            if(i==0) cin>>boss[i][j];
            else boss[i][j]=boss[i-1][boss[i-1][j]];
        }
  
    while(q--) {
        int x, k;
        cin>>x>>k;
        for(int i=0;k>0;k>>=1,i++)
            if(k&1)
                x = boss[i][x];
        
        cout<<(x?x:-1)<<ndl;
    }
}