// github.com/wisniewskij/Code
// cses.fi/problemset/task/2163
// Josephus Problem II
 
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

 
int main(){
    int n, k;
    cin>>n>>k;
    ordered_set s;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=k%s.size(); s.size(); i=(i+k)%s.size()){
        auto x = s.find_by_order(i);
        cout<<*x<<" ";
        if(s.size()==1) break;
        s.erase(x);
    }
}