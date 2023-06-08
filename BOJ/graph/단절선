#include <bits/stdc++.h>
#define MAX_N 100001

using namespace std;

vector<int> g[MAX_N], order(MAX_N), prv(MAX_N), low(MAX_N);
vector<pair<int,int>> ans;
int t;

void articulation(int v){
    order[v] = t++;
    low[v] = t;
    for(int i = 0; i < g[v].size(); i++){
        int next = g[v][i];
        if(next == prv[v]) continue;
        
        if(!order[next]){
            prv[next] = v;
            articulation(next);
            
            if(low[next] > order[v]) ans.push_back({min(v, next), max(v, next)});
            
            low[v] = min(low[v], low[next]);
        }
        else low[v] = min(low[v], order[next]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int v, e, a, b;
    cin>>v>>e;
    for(int i = 0; i < e; i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    t = 1;
    
    for(int i = 1; i <= v; i++) {
        if(!order[i]) articulation(i);
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";

    for(int i = 0; i < ans.size(); i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    
    return 0;
}
