// github.com/wisniewskij/Code
// cses.fi/problemset/task/1076
// Sliding Median
 
 
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;
 
void equalize(multiset<int> &down, multiset<int> &up){
    while(down.size()>up.size()+1){
        auto it=down.end();
        it--;
        up.insert(*it);
        down.erase(it);
    }
    while(down.size()<up.size()){
        auto it=up.begin();
        down.insert(*it);
        up.erase(it);
    }
}
 
multiset<int>::iterator last_elem(multiset<int> &s){
    auto it = s.end();
    it--;
    return it;
}
 
int main(){
    ll n,k, median;
    cin>>n>>k;
 
    vector<int> t(n);
    for(auto &x:t) cin>>x;
 
    multiset<int> down, up;
 
    for(int i=0;i<n;i++){
        if(i>=k){
            auto it = down.find(t[i-k]);
            if(it==down.end()){
                auto it2=up.find(t[i-k]);
                up.erase(it2);
            }
            else down.erase(it);
        }
        if(i<k||t[i]<=median)
            down.insert(t[i]);
        else
            up.insert(t[i]);
        if(i>=k-1){
            equalize(down, up);
            median=*last_elem(down);
            cout<<median<<" ";
        }
    }
 
}