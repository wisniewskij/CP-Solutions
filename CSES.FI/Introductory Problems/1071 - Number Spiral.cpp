// github.com/wisniewskij/Code
// cses.fi/problemset/task/1071
// Number Spiral

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
    ll q;
    cin>>q;
    while(q--){
        ll y,x;
        cin>>y>>x;
        if(y>x){
            if(y&1) cout<<(y-1)*(y-1)+x<<ndl;
            else cout<<y*y-x+1<<ndl;
        }
        else{
            if((x&1)^1) cout<<(x-1)*(x-1)+y<<ndl;
            else cout<<x*x-y+1<<ndl;
        }
    }
}