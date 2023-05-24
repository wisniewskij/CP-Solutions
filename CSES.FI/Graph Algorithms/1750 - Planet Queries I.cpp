// github.com/wisniewskij/Code
// cses.fi/problemset/task/1750
// Planet Queries I
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int up[(int)2e5+1][30];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int j=0;j<30;j++)
        for(int i=1;i<=n;i++){
            if(j==0) cin>>up[i][0];
            else up[i][j]=up[up[i][j-1]][j-1];
        }
    while(q--){
        int a,b;
        cin>>a>>b;
        for(int i=0;b>0;i++,b>>=1){
            if(b&1) a=up[a][i];
        }
        cout<<a<<ndl;
    }
    
}