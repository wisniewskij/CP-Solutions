// github.com/wisniewskij/Code
// cses.fi/problemset/task/1070
// Permutation

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
    int n;
    cin>>n;
    if(n==1) cout<<1;
    else if(n==4) cout<<"3 1 4 2";
    else if(n<5) cout<<"NO SOLUTION";
    else{
        for(int i=1;i<=n;i+=2)
            cout<<i<<" ";
        for(int i=2;i<=n;i+=2)
            cout<<i<<" ";
    }
}