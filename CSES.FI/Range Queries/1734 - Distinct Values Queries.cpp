// github.com/wisniewskij/Code
// cses.fi/problemset/task/1734
// Distinct Values Queries

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
    vector<int> t;
    SegTree(int n){
        for(this->n=1; this->n<n; this->n<<=1);
        t.assign(this->n<<1, 0);
    }
    void set(int pos, int val){
        pos+=n;
        t[pos]=val;
        for(int i=pos/2;i>0;i/=2)
            t[i]=t[i*2]+t[i*2+1];
    }
    int query(int a, int b){
        a+=n; b+=n; int ans=0;
        while(a<=b){
            if(a%2==1) ans+=t[a++];
            if(b%2==0) ans+=t[b--];
            a/=2; b/=2;
        }
        return ans;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;

    SegTree sgt(n);

    vector<int> t(n), ans(m);
    for(auto &x:t) cin>>x;

    vector<tuple<int,int,int>> q(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        q[i]={b-1,a-1,i};
    }

    sort(all(q)); 

    map<int,int> mp;
    int l=-1;
    for(auto [b,a,i]:q){
        while(l<b){
            if(mp.count(t[l+1])) sgt.set(mp[t[l+1]], 0);
            sgt.set(l+1, 1);
            mp[t[l+1]]=l+1;
            l++;
        }
        ans[i]=sgt.query(a,b);
    }
    for(auto x:ans) cout<<x<<ndl;
}