// github.com/wisniewskij/Code
// cses.fi/problemset/task/1661
// Subarray Sums II

 
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
    int n, x;
    cin>>n>>x;
    map<ll, int> m;
    m[0]=1;
    ll pfx = 0, ans=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        pfx+=tmp;
        ans+=m[pfx-x];
        m[pfx]++;
    }

    cout<<ans;
        
}