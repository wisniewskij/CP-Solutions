// github.com/wisniewskij/Code
// cses.fi/problemset/task/1141
// Playlist
 
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
    int n, maxi=0;
    cin>>n;
    map<int,int> m;
    vector<int> t(n);
    for(auto &x:t) cin>>x;
 
    int r=0;
    for(int l=0;l<n;l++){
        if(l>=r){
            r=l;
            m.clear();
            m[t[r]]=1;
        }
        while(r+1<n&&m[t[r+1]]==0){
            r++;
            m[t[r]]++;
        }
        if(l==2&&r==3){
            cout<<t[r+1]<<ndl;
            for(auto [x,y]:m) cout<<x<<" "<<y<<ndl;
        }
        maxi = max(maxi, r-l+1);
        m[t[l]]--;
    }
    cout<<maxi;
}