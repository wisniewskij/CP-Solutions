// github.com/wisniewskij/Code
// cses.fi/problemset/task/2431
// Digit Queries

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
using namespace std;
 
ll rob(ll k){
    ll a = 1, b = 9;
    while(k-a*b>0){
        k-=a*b;
        a++;
        b*=10;
    }
    ll dol = 0, gora = 10;
    for(int i=1;i<a;i++){
        dol*=10;
        dol+=9;
        gora*=10;
    }
    
    ll l=dol, r=gora;
    while(l+1<r){
        ll sr = (l+r)/2;
        if((sr-dol)*a<k) l=sr;
        else r=sr;
    }
    ll wsk = a*(r-dol);
    while(wsk%a!=k%a){
        wsk--;
        r/=10;
    }
    
    return r%10;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll k;
        cin>>k;
        cout<<rob(k)<<ndl;
    }
}