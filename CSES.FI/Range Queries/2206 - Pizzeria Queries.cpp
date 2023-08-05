// github.com/wisniewskij/Code
// cses.fi/problemset/task/2206
// Pizzeria Queries

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
    int n; vector<ll> lsum, rsum;
    SegTree(int n){
        for(this->n=1;this->n<n;this->n<<=1);
        lsum.assign(this->n<<1, INF);
        rsum.assign(this->n<<1, INF);
    }
    void set(int pos, int val){
        pos+=n; lsum[pos]=val+pos-n; rsum[pos]=val-pos+n; 
        for(int i=pos/2; i>0; i/=2){
            lsum[i]=min(lsum[i*2],lsum[i*2+1]);
            rsum[i]=min(rsum[i*2],rsum[i*2+1]);
        }
    }
    ll ql(int pos) {
        ll l=pos+n, r=2*n-1, ans=INF;
        while (l<=r) {
            if(l%2==1)  ans=min(ans, lsum[l++]);
            if(r%2==0)  ans=min(ans, lsum[r--]);
            l/=2; r/=2;
        }
        return ans;
    }
    ll qr(int pos) {
        ll l=n, r=pos+n, ans=INF;
        while (l<=r) {
            if(l%2==1)  ans=min(ans, rsum[l++]);
            if(r%2==0)  ans=min(ans, rsum[r--]);
            l/=2; r/=2;
        }
        return ans;
    }
    ll q(int pos){
        return min(ql(pos)-pos, qr(pos)+pos);
    }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
    
    SegTree sgt(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sgt.set(i, tmp);
    }

    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int k, y;
            cin>>k>>y;
            sgt.set(k-1, y);
        }
        else{
            int k;
            cin>>k;
            cout<<sgt.q(k-1)<<ndl;
        }
    }
}