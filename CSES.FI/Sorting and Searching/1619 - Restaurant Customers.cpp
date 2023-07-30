// github.com/wisniewskij/Code
// cses.fi/problemset/task/1619
// Restaurant Customers

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
    map<int, int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        m[a]++;
        m[b+1]--;
    }

    int l=0, ans=0;
    for(auto [x,y]:m){
        l+=y;
        ans=max(ans, l);
    }

    cout<<ans;

}
