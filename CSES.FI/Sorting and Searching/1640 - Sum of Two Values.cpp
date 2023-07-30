// github.com/wisniewskij/Code
// cses.fi/problemset/task/1640
// Sum of Two Values

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
    int n, m;
    cin>>n>>m;
    vector<int> tab(n);
    map<int,int> idx;
    for(int i=0;i<n;i++){
        cin>>tab[i];
        idx[tab[i]]=i+1;
    }
    for(int i=0;i<n;i++)
        if(idx.count(m-tab[i])&&idx[m-tab[i]]!=i+1){
            cout<<i+1<<" "<<idx[m-tab[i]];
            return 0;
        }
    cout<<"IMPOSSIBLE";
}
