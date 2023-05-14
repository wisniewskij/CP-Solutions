// github.com/wisniewskij/Code
// cses.fi/problemset/task/1649
// Dynamic Range Minimum Queries

#include <bits/stdc++.h>
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
class SegTree{
    public:
    int n;
    vector<ll> t;
    SegTree(int n){
        this->n=1;
        while(this->n<n) this->n<<=1;
        t.assign(2*(this->n),0);        
    }
    void set(int pos, int val){
        pos+=n;
        t[pos]=val;
        pos>>=1;
        while(pos>0){
            t[pos]=min(t[pos<<1],t[(pos<<1)+1]);
            pos>>=1;
        }
    }
    ll q(int a, int b){
        a+=n; b+=n; 
        ll mini=INF;
        while (a<=b){
            if(a&1) mini=min(mini, t[a++]);
            if((b&1)^1) mini=min(mini, t[b--]);
            a>>=1;
            b>>=1;
        }
        return mini;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    SegTree segt(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        segt.set(i, tmp);
    }
 
    while(q--){
        int l,a,b;
        cin>>l>>a>>b;
        if(l==1){
            segt.set(a-1, b);
        }
        else{
            cout<<segt.q(a-1, b-1)<<ndl;
        }
    }
}