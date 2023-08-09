// github.com/wisniewskij/Code
// cses.fi/problemset/task/1735
// Range Updates and Sums
 
#include <bits/stdc++.h>
#define ndl '\n'
#define ll long long
#define INF 1e18
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
class SegTree{
    public:
    int n;
    vector<ll> t, ta, ts;
    SegTree(int n){
        for(this->n=1;this->n<n;this->n<<=1);
        t.assign(this->n<<1, 0);
        ta.assign(this->n<<1, 0);
        ts.assign(this->n<<1, 0);
    }
    void propagate(int k, int x, int y){
        int len = y-x+1;
        if(ts[k]) t[k]=len*ts[k];
        t[k]+=ta[k]*len;
        if(x!=y){
            if(ts[k]){
                ts[k*2]=ts[k*2+1]=ts[k];
                ta[k*2]=ta[k*2+1]=0;
            } 
            ta[k*2]+=ta[k];
            ta[k*2+1]+=ta[k];
        }
        ts[k]=ta[k]=0;
    }
    void set(int a, int b, int val, int k, int x, int y){
        if(y<a||b<x) return;
        if(a<=x&&y<=b){
            ts[k]=val;
            ta[k]=0;
        }
        else{
            propagate(k, x, y);
            int mid=(x+y)/2;
            set(a, b, val, k*2, x, mid);
            set(a, b, val, k*2+1, mid+1, y);
            propagate(k*2, x, mid);
            propagate(k*2+1, mid+1, y);
            t[k]=t[k*2]+t[k*2+1];
        }
    }
    void add(int a, int b, int val, int k, int x, int y){
        if(y<a||b<x) return;
        if(a<=x&&y<=b) ta[k]+=val;
        else{
            propagate(k, x, y);
            int mid=(x+y)/2;
            add(a, b, val, k*2, x, mid);
            add(a, b, val, k*2+1, mid+1, y);
            propagate(k*2, x, mid);
            propagate(k*2+1, mid+1, y);
            t[k]=t[k*2]+t[k*2+1];
        }
    }
    ll query(int a, int b, int k, int x, int y){
        if(y<a||b<x) return 0;
        propagate(k, x, y);
        if(a<=x&&y<=b) return t[k];
        else{
            int mid=(x+y)/2;
            return query(a, b, k*2, x, mid)+query(a, b, k*2+1, mid+1, y);
        }
    }
    
};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    SegTree sgt(n);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sgt.add(i, i, tmp, 1, 0, sgt.n-1);
    }
    
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int a, b, val;
            cin>>a>>b>>val;
            sgt.add(a-1, b-1, val, 1, 0, sgt.n-1);
        }
        else if(x==2){
            int a, b, val;
            cin>>a>>b>>val;
            sgt.set(a-1, b-1, val, 1, 0, sgt.n-1);
        }
        else{
            int a, b;
            cin>>a>>b;
            cout<<sgt.query(a-1, b-1, 1, 0, sgt.n-1)<<ndl;
        }
    }
}