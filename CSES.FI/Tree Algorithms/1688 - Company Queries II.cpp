// github.com/wisniewskij/Code
// cses.fi/problemset/task/1688
// Company Queries II

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
    vector<vector<int>> up(n+1, vector<int>(__lg(n)+1));
    vector<int> depth(n+1);

    for(int j=0;j<=__lg(n);j++)
        for(int i=2;i<=n;i++){
            if(j==0) cin>>up[i][j];
            else{
                up[i][j]=up[up[i][j-1]][j-1];
                depth[i]=depth[up[i][0]]+1;
            }
        }

    while(q--){
        int a,b;
        cin>>a>>b;

        if(depth[a]>depth[b]) swap(a,b);

        int c = depth[b]-depth[a];
        for(int i=0;c>0;i++,c>>=1)
            if(c&1) b=up[b][i];
        
        if(a==b){
            cout<<a<<" ";
            continue;
        }

        for(int i=__lg(n);i>=0;i--)
            while(up[a][i]!=up[b][i]){
                a=up[a][i];
                b=up[b][i];
            }

        cout<<up[a][0]<<" ";
    }
}