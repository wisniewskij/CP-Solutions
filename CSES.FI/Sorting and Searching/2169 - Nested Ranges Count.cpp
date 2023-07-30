// github.com/wisniewskij/Code
// cses.fi/problemset/task/2169
// Nested Ranges Count
 
 
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

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

 
int main(){
    int n;
    cin>>n;
    vector<tuple<int,int,int>> t(n);
    vector<int> does(n), is(n);
    map<int, int> idx;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        t[i]={a,b,i};
    }
    sort(all(t), [](tuple<int,int,int>a, tuple<int,int,int>b){auto [a1,a2,a3]=a; auto [b1,b2,b3]=b; if(a1==b1) return a2>b2; return a1<b1;});
    ordered_set s;
    for(auto [a,b,i]:t){
        is[i]=s.size()-s.order_of_key({b,0});
        s.insert({b, idx[b]});
        idx[b]++;
    }
    sort(all(t), [](tuple<int,int,int>a, tuple<int,int,int>b){auto [a1,a2,a3]=a; auto [b1,b2,b3]=b; if(a2==b2) return a1>b1; return a2<b2;});
 
    s.clear();
    idx.clear();
    for(auto [a,b,i]:t){
        does[i]=s.size()-s.order_of_key({a,0});
        s.insert({a, idx[a]});
        idx[a]++;
    }
 
    for(int i=0;i<n;i++)
        cout<<does[i]<<" ";
    cout<<ndl;
    for(int i=0;i<n;i++)
        cout<<is[i]<<" ";
}