// github.com/wisniewskij/Code
// cses.fi/problemset/task/1744
// Rectangle Cutting
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000001
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
using namespace std;

ll dp[501][501];

int main(){
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++){
            if(i==1||j==1) dp[i][j]=max(i,j)-1;
            else if(i==j) dp[i][j]=0;
            else{
                dp[i][j]=INF;
                for(int k=1;k<i;k++)
                    dp[i][j]=min(dp[i][j], 1+dp[i-k][j]+dp[k][j]);
                for(int k=1;k<j;k++)
                    dp[i][j]=min(dp[i][j], 1+dp[i][j-k]+dp[i][k]);
            }
        }
    
    cout<<dp[a][b];
}

