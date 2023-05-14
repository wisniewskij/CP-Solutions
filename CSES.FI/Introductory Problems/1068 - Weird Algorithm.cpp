// github.com/wisniewskij/Code
// cses.fi/problemset/task/1068
// Weird Algorithm

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
    ll n;
    cin>>n;
    while(true){
        cout<<n<<" ";
        if(n==1) break;
        if(n&1) n=n*3+1;
        else n>>=1;
    }
} 

