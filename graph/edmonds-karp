//
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000

using namespace std;

int n = 6;
int cap[MAX][MAX];
int flow[MAX][MAX];
int visit[MAX];

vector<int> v[MAX];

int edmonds_karp(int s, int e) {
	int total = 0;
	while (1) {
		for(int i = 0; i < MAX; i++) visit[i] = -1;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < v[x].size(); i++) {
				int j = v[x][i];
				// 방문하지 않은 정점 중 용량이 남은 경우
				if (cap[x][j] - flow[x][j] > 0 && visit[j] == -1) { // 흐를 수 있는 경우 && 방문하지 않은 경우
					q.push(j);
					visit[j] = x; // 경로를 기억함
					if (j == e) break; // 도착지에 도달한 경우
				}
			}
			if(visit[e] != -1) break;
		}

		if (visit[e] == -1) break;
		
		int f = INF;

		for (int i = e; i != s; i = visit[i]) {
			f = min(f, cap[visit[i]][i] - flow[visit[i]][i]);
		}

		for (int i = e; i != s; i = visit[i]) {
			flow[visit[i]][i] += f;
			flow[i][visit[i]] -= f;
		}
		total += f;
	}
	return total;
}

int main(){
    int n, x;
    char a, b;
    cin>>n;
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            cap[i][j] = 0;
    for(int i = 0; i < n; i++) {
        cin>>a>>b>>x;
        v[a-'A'].push_back(b-'A');
        v[b-'A'].push_back(a-'A');
        cap[a-'A'][b-'A'] += x;
        cap[b-'A'][a-'A'] += x;
    }
    cout<<edmonds_karp(0, 25);
}
