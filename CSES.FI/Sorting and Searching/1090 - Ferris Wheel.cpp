// github.com/wisniewskij/Code
// cses.fi/problemset/task/1090
// Ferris Wheel

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
    for(auto &x:tab) cin>>x;
    sort(all(tab));
    int j=n-1, l=0;
    for(int i=0;i<j;i++){
        while(i<j && tab[i]+tab[j]>m) j--;
        if(i<j){
            l++;
            j--;
        } 
    }
    cout<<n-l;
}
