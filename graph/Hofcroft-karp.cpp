#include <bits/stdc++.h>

using namespace std;

struct Hof {
    static const int MAX = 2020;
    static const int INF = 1000000000;

    int n, m, cnt, A[MAX], B[MAX], dist[MAX];
    bool visit[MAX];
    vector<int> grp[MAX];

    Hof(){}
    Hof(int N){
        n = N;
        cnt = 0;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        memset(dist, 0, sizeof(dist));
        memset(visit, 0, sizeof(visit));
    }

    void push_back(int a, int b){
        grp[a].push_back(b);
    }

    void bfs(){
        queue<int> q;
        for(int i=0; i < n; i++){
            if(!visit[i]){
                dist[i] = 0;
                q.push(i);
            }
            else dist[i] = INF;
        }

        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(int b: grp[a]){
                if(B[b] != -1 && dist[B[b]] == INF){
                    dist[B[b]] = dist[a] + 1;
                    q.push(B[b]);
                }
            }
        }
    }

    bool dfs(int a){
        for(int b: grp[a]){
            if(B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b])){
                visit[a] = true;
                A[a] = b;
                B[b] = a;
                return true;
            }
        }
        return false;
    }

    void solve(){
        while(1){
            bfs();

            int flow = 0;
            for(int i=0; i<n; i++)
                if(!visit[i] && dfs(i)) flow++;

            if(flow == 0) break;
            cnt += flow;
        }
    }
};
