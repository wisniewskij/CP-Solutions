// github.com/wisniewskij/Code
// cses.fi/problemset/task/1737/
// Range Queries and Copies

#include <bits/stdc++.h>
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()

using namespace std;

struct node
{
    ll value;
    int name;
    int x, y;
    node *left, *right;
    node(ll v, int x, int y, int name) : value(v), x(x), y(y), name(name)
    {
        left = right = nullptr;
    }
};

void setq(int a, ll val, node *k, node *o)
{
    if (k->x == k->y && k->y == a)
        k->value = val;
    else
    {
        int mid = (k->x + k->y) / 2;
        if (a <= mid)
        {
            if (!k->left)
                k->left = new node(0, k->x, mid, k->name * 2);
            setq(a, val, k->left, (o && o->left ? o->left : nullptr));
        }
        else if (o)
            k->left = o->left;

        if (a > mid)
        {
            if (!k->right)
                k->right = new node(0, mid + 1, k->y, k->name * 2 + 1);
            setq(a, val, k->right, (o && o->right ? o->right : nullptr));
        }
        else if (o)
            k->right = o->right;

        k->value = (k->left ? k->left->value : 0) + (k->right ? k->right->value : 0);
    }
}

ll query(int a, int b, node *k)
{
    if (k->y < a || b < k->x)
        return 0;
    if (a <= k->x && k->y <= b)
        return k->value;
    else
    {
        int mid = (k->x + k->y) / 2;
        return query(a, b, k->right) + query(a, b, k->left);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, m;
    cin >> n >> q;
    for (m = 1; m < n; m <<= 1)
        ;
    vector<int> idx = {0, 0};
    vector<node *> roots = {new node(0, 0, m - 1, 1)};
    for (int i = 0; i < m; i++)
    {
        if (i < n)
        {
            ll tmp;
            cin >> tmp;
            setq(i, tmp, roots[0], nullptr);
        }
        else
            setq(i, 0, roots[0], nullptr);
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        if (x == 1)
        {
            int a, x;
            cin >> a >> x;
            roots.push_back(new node(0, 0, m - 1, 1));
            setq(a - 1, x, roots.back(), roots[idx[k]]);
            idx[k] = roots.size() - 1;
        }
        else if (x == 2)
        {
            int a, b;
            cin >> a >> b;
            cout << query(a - 1, b - 1, roots[idx[k]]) << ndl;
        }
        else
        {
            idx.push_back(idx[k]);
        }
    }
}