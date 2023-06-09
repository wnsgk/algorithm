#include <bits/stdc++.h>

using namespace std;

struct Line {
    int e, dist;
    Line(int E, int D){
        e = E; dist = D;
    }
};

vector<Line> v[1001];
vector<int> dst(1001, 2000000000);

int dijkstra(int s, int e){
    priority_queue<pair<int,int>> q;
    q.push({0, s});
    int mn = -1;
    dst[s] = 0;
    while(!q.empty()){
        int d = -q.top().first;
        int x = q.top().second;
        q.pop();
        if(dst[x] < d) continue;
        if(x == e){
            mn = d;
            break;
        }
        for(int i = 0; i < v[x].size(); i++){
            int nx = v[x][i].e;
            int nd = v[x][i].dist;
            if(d + nd < dst[nx]){
                dst[nx] = d + nd;
                q.push({-dst[nx], nx});
            }
        }
    }
    return mn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m, s, e, a, b, c;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        v[a].push_back(Line(b, c));
    }
    cin>>s>>e;
    cout<<dijkstra(s, e);

    return 0;
}
