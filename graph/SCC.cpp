#include <bits/stdc++.h>

using namespace std;

struct SCC {
    int n, idx, start;
    vector<vector<int>> v, rev_v;
    vector<vector<int>> scc, scc_grp;
    vector<int> visit, num;
    stack<int> stk;
    vector<int> ind;

    SCC() {};
    SCC(int N) {
        n = N; idx = 0;
        v.resize(N+1);
        rev_v.resize(N+1);
        visit.resize(N+1);
        num.resize(N+1);
        scc.clear();
    }

    void push_edge(int x, int y){
        v[x].push_back(y);
        rev_v[y].push_back(x);
    }

    void dfs(int s){

        visit[s] = 1;

        for(int i = 0; i < v[s].size(); i++){
            int next = v[s][i];
            if(visit[next]) continue;
            dfs(next);
        }
        stk.push(s);
    }

    void rev_dfs(int s){
        visit[s] = 1;
        num[s] = idx;
        for(int i = 0; i < rev_v[s].size(); i++){
            int next = rev_v[s][i];
            if(visit[next]) continue;
            rev_dfs(next);
        }
    }

    void init(){
        for(int i = 1; i <= n; i++){
            if(visit[i]) continue;
            dfs(i);
        }

        visit.clear();
        visit.resize(n + 1);
        while(!stk.empty()){
            int x = stk.top();
            stk.pop();
            if(visit[x]) continue;
            rev_dfs(x);
            idx++;
        }
        scc.resize(idx);
        for(int i = 1; i <= n; i++){
            scc[num[i]].push_back(i);
        }
    }

    void topo(){
        start = 0;
        scc_grp.resize(idx);
        ind.resize(idx);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < v[i].size(); j++){
                if(num[v[i][j]] != num[i]) {
                    scc_grp[num[i]].push_back(num[v[i][j]]);
                }
            }
        }
        for(int i = 0; i < idx; i++){
            sort(scc_grp[i].begin(), scc_grp[i].end());
            unique(scc_grp[i].begin(), scc_grp[i].end());
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < v[i].size(); j++){
                if(num[v[i][j]] != num[i]) {
                    ind[num[v[i][j]]]++;
                }
            }
        }

        for(int i = 0; i < idx; i++){
            if(ind[i] == 0) start++;
        }
    }

    int size(){
        return scc.size();
    }

    int getSccNum(int x){
        return num[x];
    }

    vector<vector<int>> getScc(){
        return scc;
    }
};