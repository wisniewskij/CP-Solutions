// github.com/wisniewskij/Code
// cses.fi/problemset/task/1647
// Static Range Minimum Queries

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
    ll n,q, N=0;
    cin>>n>>q;
    for(int i=1;i<=n;i<<=1) N++;
    vector<vector<int>> smq(n, vector<int>(N));
    for(int j=0;j<N;j++)
        for(int i=0;i<n&&i+(1<<j)-1<n;i++){
            if(j==0) cin>>smq[i][0];
            else
                smq[i][j]=min(smq[i][j-1],smq[i+(1<<(j-1))][j-1]);
        }
    
    while(q--){
        int a,b;
        cin>>a>>b;
        int len=b-a+1, minimum=INF;
        a--;
        for(int i=0;len>0;len>>=1,i++)
            if(len&1){
                minimum=min(minimum, smq[a][i]);
                a+=1<<i;
            }
        cout<<minimum<<ndl;
    }
}