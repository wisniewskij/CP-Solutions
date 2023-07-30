// github.com/wisniewskij/Code
// cses.fi/problemset/task/1077
// Sliding Cost
 
 
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;
 
void equalize(multiset<int> &down, multiset<int> &up, ll &downsum, ll &upsum){
    while(down.size()>up.size()+1){
        auto it=down.end();
        it--;
        upsum+=*it;
        downsum-=*it;
        up.insert(*it);
        down.erase(it);
    }
    while(down.size()<up.size()){
        auto it=up.begin();
        upsum-=*it;
        downsum+=*it;
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
    ll n,k, median, upsum=0, downsum=0;
    cin>>n>>k;
 
    vector<int> t(n);
    for(auto &x:t) cin>>x;
 
    multiset<int> down, up;
 
    for(int i=0;i<n;i++){
        if(i>=k){
            auto it = down.find(t[i-k]);
            if(it==down.end()){
                auto it2=up.find(t[i-k]);
                upsum-=t[i-k];
                up.erase(it2);
            }
            else{
                down.erase(it);
                downsum-=t[i-k];
            }
        }
        if(i<k||t[i]<=median){
            down.insert(t[i]);
            downsum+=t[i];
        }
        else{
            up.insert(t[i]);
            upsum+=t[i];
        }
        if(i>=k-1){
            equalize(down, up, downsum, upsum);
            median=*last_elem(down);
            cout<<upsum-median*up.size()+median*down.size()-downsum<<" ";
        }
    }
 
}