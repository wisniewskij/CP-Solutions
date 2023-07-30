// github.com/wisniewskij/Code
// cses.fi/problemset/task/2217
// Collecting Numbers II

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
    int n, m, ans = 1;
    cin>>n>>m;
    vector<int> t(n+1), no(n+1);
    for(int i=1;i<=n;i++){
        cin>>no[i];
        t[no[i]]=i;
    }
    for(int i=2;i<=n;i++){
        if(t[i]<t[i-1]) ans++;
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        swap(no[a], no[b]);
        swap(t[no[a]], t[no[b]]);
        if(no[a]>no[b]) swap(a, b);
        
        ans+=(t[no[b]]>t[no[a]-1])-(t[no[a]]>t[no[a]-1]);
        ans+=(t[no[a]]<t[no[b]+1])-(t[no[b]]<t[no[b]+1]);
        if(no[a]+1==no[b])
            ans+=(t[no[b]]<t[no[a]])-(t[no[a]]<t[no[b]]);
        else{
            ans+=(t[no[a]]>t[no[b]-1])-(t[no[b]]>t[no[b]-1]);
            ans+=(t[no[b]]<t[no[a]+1])-(t[no[a]]<t[no[a]+1]);
        }

        cout<<ans<<ndl;
    }
    
}
