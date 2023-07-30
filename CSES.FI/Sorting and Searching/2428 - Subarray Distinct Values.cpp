// github.com/wisniewskij/Code
// cses.fi/problemset/task/2428
// Subarray Distinct Values
 
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
    int n, k;
    cin>>n>>k;
    map<int,int> m;
    vector<int> t(n);
    for(auto &x:t) cin>>x;
    ll r=0, d=0, ans=n;
    for(int l=0;l<n;l++){
        if(r<=l){
            r=l;
            m.clear();
            m[t[l]]=1;
            d=1;
        }
        while(r+1<n&&(d<k||m[t[r+1]]>0)){
            r++;
            ans+=r-l;
            if(!m[t[r]]) d++;
            m[t[r]]++;
        }
        m[t[l]]--;
        if(!m[t[l]]) d--;
    }
    cout<<ans;
}