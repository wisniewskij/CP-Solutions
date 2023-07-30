// github.com/wisniewskij/Code
// cses.fi/problemset/task/2216
// Collecting Numbers

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
    int n, ans = 1;
    cin>>n;
    vector<int> t(n+1);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        t[tmp]=i+1;
    }
    for(int i=2;i<=n;i++){
        if(t[i]<t[i-1]) ans++;
    }
    cout<<ans;
}
