#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int sqn, tot=0;
vector<int> v(100001);
vector<int> cnt(1000001);
    
struct Query {
	int idx, s, e;
	bool operator < (Query &x){
		if(s/sqn != x.s/sqn) return s/sqn < x.s/sqn;
		return e < x.e;
	}
};

void mi(int s, int e) {
    for(int i = s; i <= e; i++){
        cnt[v[i]]--;
        if(cnt[v[i]]==0) tot--;
    }
}

void pl(int s, int e) {
    for(int i = s; i <= e; i++){
        if(cnt[v[i]]==0) tot++;
        cnt[v[i]]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin>>n;
    sqn = sqrt(n);
    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }
    cin>>m;
    vector<Query> q(m);
    for(int i = 0; i < m; i++){
        cin>>q[i].s>>q[i].e;
        q[i].idx = i;
    }
    sort(q.begin(), q.end());
    for(int i = q[0].s; i <= q[0].e; i++){
        if(cnt[v[i]] == 0)  tot++;
        cnt[v[i]]++;
    }
    vector<int> ans(m);
    ans[q[0].idx] = tot;
    ll l = q[0].s;
    ll r = q[0].e;
    for(int i = 1; i < m; i++){
        if(q[i].s < l) pl(q[i].s, l-1);
        if(q[i].s > l) mi(l, q[i].s-1);
        if(q[i].e < r) mi(q[i].e+1, r);
        if(q[i].e > r) pl(r+1, q[i].e);
        
        ans[q[i].idx] = tot;
        l = q[i].s;
        r = q[i].e;
    }
    
    for(int i = 0; i < m; i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}
