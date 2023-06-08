#include <bits/stdc++.h>

using namespace std;

vector<int> mst[100003 << 2];

void update(int node, int l, int r, int idx, int k)
{
    if (idx < l || r < idx) return;
    mst[node].push_back(k);
    if (l < r) {
        int mid = (l+r)/2;
        update(node*2, l, mid, idx, k);
        update(node*2+1, mid + 1, r, idx, k);
    }
}

int query(int node, int l, int r, int start, int end, int k)
{
    if (end < l || r < start) return 0;
    if (start <= l && r <= end) return mst[node].end() - upper_bound(mst[node].begin(), mst[node].end(), k);
    
    int mid = (l+r)/2;
    return query(node*2, l, mid, start, end, k) + query(node*2+1, mid + 1, r, start, end, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, i, j, k;

    cin>>n;
    vector<int> v(100001), p(1000001);
    for(int i = 1; i <= n; i++) cin>>v[i];
    
    for(int i = 1; i <= n; i++){
        if(p[v[i]] == 0) {
            p[v[i]] = i;
            v[i] = n+1;
        }
        else {
            v[p[v[i]]] = i;
            p[v[i]] = i;
            v[i] = n+1;
        }
    }
    for(i = 1; i <= n; i++) {
        update(1, 1, n, i, v[i]);
    }

    for(i = 1; i <= n*4; i++)
        sort(mst[i].begin(), mst[i].end());
    cin>>m;
    while(m--){
        cin>>i>>j;
        cout<<query(1, 1, n, i, j, j)<<"\n";
    }

    return 0;
}
