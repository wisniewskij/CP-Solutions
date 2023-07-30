// github.com/wisniewskij/Code
// cses.fi/problemset/task/1660
// Subarray Sums I
 
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
    int n, m;
    cin>>n>>m;
    vector<int> t(n);
    for(auto &x:t) cin>>x;
    int r=0, sum=0, ans=0;
    for(int l=0;l<n;l++){
        if(r<=l){
            r=l;
            sum=t[l];
        }
        while(r+1<n&&sum<m) sum+=t[++r];
        if(sum==m) ans++;
        sum-=t[l];
    }
    cout<<ans;
}