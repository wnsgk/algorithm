#include <bits/stdc++.h>
#define MAX_N 10001

using namespace std;

vector<int> g[MAX_N], ans, order(MAX_N), prv(MAX_N), low(MAX_N), finish(MAX_N);
int t;

void articulation(int v){
    order[v] = t++;
    low[v] = t;
    int child = 0;
    for(int i = 0; i < g[v].size(); i++){
        int next = g[v][i];
        if(next == prv[v]) continue;
        
        if(!order[next]){
            prv[next] = v;
            child++;
            articulation(next);
            
            if(!prv[v] && child > 1) {
                finish[v] = 1;
            }
            else if(prv[v] != 0 && low[next] >= order[v]) {
                finish[v] = 1;
            }
            
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
    for(int i = 1; i <= v; i++) {
        if(finish[i]) ans.push_back(i);
    }
    
    cout<<ans.size()<<"\n";

    for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
    
    return 0;
}
