// github.com/wisniewskij/Code
// cses.fi/problemset/task/1072
// Two Knights

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        if(i==1) cout<<0<<ndl;
        else if(i==2) cout<<6<<ndl;
        else if(i==3) cout<<28<<ndl;
        else cout<< (i*i*(i*i-1) - (48 + (i-4)*40 + (i-4)*(i-4)*8))/2<<ndl;
    }
}