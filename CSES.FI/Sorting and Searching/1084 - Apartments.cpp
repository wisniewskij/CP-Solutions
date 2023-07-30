// github.com/wisniewskij/Code
// cses.fi/problemset/task/1084
// Apartments

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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> t(n), ap(m);
    for(auto &x:t) cin>>x;
    for(auto &x:ap) cin>>x;
    sort(all(t));
    sort(all(ap));
    int j=0, l=0;
    for(int i=0;i<n && j<m;i++){
        while(j<m && t[i]-k>ap[j])
            j++;        
        if(j<m && abs(t[i]-ap[j])<=k){
            j++;
            l++;
        }
    }
    cout<<l;
}
