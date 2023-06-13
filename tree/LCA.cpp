#include <bits/stdc++.h>

using namespace std;
int depth[100001];
int parent[100001][17];
vector<int> v[100001];
int n;

void dfs(int cur, int p){
    parent[cur][0] = p;
    depth[cur] = depth[p]+1;
    for(int i = 0; i < v[cur].size(); i++){
        if(v[cur][i] == p) continue;
        
        dfs(v[cur][i], cur);
    }
}

void make_lca(){
    for(int i = 1; i < 17; i++){
        for(int j = 1; j <= n; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) return lca(b, a);
    while(depth[a] != depth[b]){
        int x = depth[a] - depth[b];
        int idx = -1;
        for(int i = 1; i <= x; i*=2){
            idx++;
        }
        a = parent[a][idx];
    }
    while(a != b){
        int idx = 0;
        for(int i = 0; parent[a][i] != parent[b][i]; i++){
            idx = i;
        }
        a = parent[a][idx];
        b = parent[b][idx];
    }
    return a;
}
                
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int m, a, b;
    cin>>n;
    for(int i = 0; i < n-1; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    depth[1] = 1;
    dfs(1, 0);
    make_lca();
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
    return 0;
}
