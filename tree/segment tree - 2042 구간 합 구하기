/*
G1
*/

#include<iostream>

using namespace std;
long long vn[1000001], segtree[4000001];
long long init_segtree(long long node, long long start, long long end) {
    if (start == end)    
        return segtree[node] = vn[start];   

    long long mid = (start + end) / 2;

    return segtree[node] = init_segtree(node * 2, start, mid) + init_segtree(node * 2 + 1, mid + 1, end);
}

long long sum(long long node, long long start, long long end, long long left, long long right) {
    if (left > end || right < start) return 0;

    if (left <= start && end <= right) return segtree[node];

    long long mid = (start + end) / 2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

void update(long long node, long long start, long long end, long long index, long long diff) {
    if (index < start || index > end) return; 
    segtree[node] += diff; 

    if (start == end) return;
    long long mid = (start + end) / 2;
    update(node*2, start, mid, index, diff);
    update(node*2+1, mid+1, end, index, diff);
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k, a, b;
    long long c;
    cin>>n>>m>>k;

    for(long long i = 1; i < n+1; i++) 
    {
        cin>>vn[i];
    }
    
    init_segtree(1, 1, n);
    for(long long i = 0; i < m+k; i++)
    {
        cin>>a>>b>>c;
        if(a == 1)
        {
            update(1, 1, n, b, c - vn[b]);
            vn[b] = c;
        }
        else
        {
            cout<<sum(1, 1, n, b, c)<<"\n";
        }
    }
    
    return 0;
}
