// github.com/wisniewskij/Code
// cses.fi/problemset/task/1144
// Salary Queries

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
    int n; vector<ll> t;
    SegTree(int n){
        for(this->n=1;this->n<n;this->n<<=1);
        t.assign(this->n<<1, 0);
    }
    void add(int pos, int val){
        pos+=n; t[pos]+=val;
        for(int i=pos/2; i>0; i/=2) t[i]=t[i*2]+t[i*2+1];
    }
    ll querry(int a, int b){
        ll ans=0; a+=this->n; b+=this->n;
        while(a<=b){
            if(a&1) ans+=t[a++];
            if((b&1)^1) ans+=t[b--];
            a/=2; b/=2;
        }
        return ans;
    }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;

    vector<int> employee(n), val(n);
    for(int i=0;i<n;i++) cin>>employee[i];
    
    val=employee;

    vector<tuple<char,int,int>> queries;
    for(int i=0;i<q;i++){
        char c; int k, x;
        cin>>c>>k>>x;
        val.push_back(x); val.push_back(k);   
        queries.push_back({c,k,x});
    }

    map<int,int> compression;
    sort(all(val));
    int prev=-1, cnt=0;
    for(auto x:val){
        if(x!=prev) compression[x]=cnt++;
        prev=x;
    }   

    SegTree sg(cnt);
    for(auto x:employee) sg.add(compression[x], 1);

    for(auto [c,k,x]:queries){
        if(c=='!'){
            sg.add(compression[employee[k-1]], -1);
            employee[k-1]=x;
            sg.add(compression[x], 1);
        }
        else cout<<sg.querry(compression[k], compression[x])<<ndl;
    }
}