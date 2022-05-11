#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> v(100001);
vector<vector<int>> ac(50001, vector<int>(17,-1));
vector<int> depth(50001, -1);
int n, m;

void dfs(int node)
{
    for(int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        if(ac[next][0] == -1) 
        {
            ac[next][0] = node;
            depth[next] = depth[node]+1;
            dfs(next);
        }
    }
}

int find_LCA(int u, int t)
{
    if(depth[u] < depth[t])
    {
        int tmp = u;
        u = t;
        t = tmp;
    }
    
    int diff = depth[u] - depth[t];
    for(int i = 0; diff != 0; i++)
    {
        if(diff%2 == 1) u = ac[u][i];
        diff/=2;
    }
    
    if(u != t)
    {
        for(int i = 16; i >= 0; i--)
        {
            if(ac[u][i] != -1 && ac[u][i] != ac[t][i])
            {
                u = ac[u][i];
                t = ac[t][i];
            }
    
        }
        return ac[u][0];
    }
    return u;
}

void connect()
{
    for(int i = 1; i < 17; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ac[j][i] = ac[ac[j][i-1]][i-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    int x, y;
    for(int i = 1; i < n; i++)
    {
       cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    depth[1] = 0;
    ac[1][0] = 1;
    dfs(1);
    connect();
    cin>>m;
    while(m--){
        cin>>x>>y;
        cout<<find_LCA(x, y)<<"\n";
    }
    return 0;
}
