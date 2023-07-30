// github.com/wisniewskij/Code
// cses.fi/problemset/task/1641
// Sum of Three Values

 
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
    int n, x;
    cin>>n>>x;
    vector<int> t(n+1);
    map<int,vector<int>> m;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        m[t[i]].push_back(i);
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(m.count(x-t[i]-t[j])){
                for(auto it:m[x-t[i]-t[j]])
                    if(it!=i&&it!=j){
                        cout<<i<<" "<<j<<" "<<it<<ndl;
                        return 0;
                    }
            }
        }
    }

    cout<<"IMPOSSIBLE"<<ndl;
    
}