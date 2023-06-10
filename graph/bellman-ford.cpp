#include <bits/stdc++.h>

using namespace std;

#define MAX 2000000000
typedef long long ll;

vector<ll> dist(501, MAX);

struct Edge {
    int s, e, d;
    Edge(int S, int E, int D){
        s = S; e = E; d = D;
    }
};

void bellman_ford(){
    
    vector<Edge> edge;
    int n, m, a, b, c;
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        cin>>a>>b>>c;
        edge.push_back(Edge(a, b, c));
    }
    dist[1] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int s = edge[j].s;
            int e = edge[j].e;
            int d = edge[j].d;
            if(dist[s] == MAX) continue;
            if(dist[e] > dist[s] + d) dist[e] = dist[s] + d;
        }
    }
    for(int j = 0; j < m; j++){
        int s = edge[j].s;
        int e = edge[j].e;
        int d = edge[j].d;
        if(dist[s] == MAX) continue;
        if(dist[e] > dist[s] + d) {
            cout<<-1;   //무한히 줄어드는 경로
            return ;
        }
    }
    for(int i = 2; i <= n; i++){
        if(dist[i] == MAX) cout<<"-1\n";   //갈 수 없는 경로
        else cout<<dist[i]<<"\n";
    }
}
