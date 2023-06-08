#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

vector<int> visit(10001);

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    int answer = 0;
    int v, e, a, b, c, x, y;
    cin>>v>>e;
    vector<vector<pair<int,int>>> costs(v+1);
    int mn = INT_MAX;
    for(int i = 0; i < e; i++)
    {
        cin>>a>>b>>c;
        if(mn > c)
        {
            mn = c;
            x = a;
            y = b;
        }
        costs[a].push_back(make_pair(b, c));
        costs[b].push_back(make_pair(a, c));
    }
    priority_queue<pair<int,int>> q;
    visit[x] = 1;
    visit[y] = 1;
    for(int i = 0; i < costs[x].size(); i++)
    {
        q.push(make_pair(-costs[x][i].second, costs[x][i].first));
    }
    for(int i = 0; i < costs[y].size(); i++)
    {
        q.push(make_pair(-costs[y][i].second, costs[y][i].first));
    }
    int n = 2;
    int ans = mn;
    while(n<v)
    {
        int d = -q.top().first;
        int next = q.top().second;
        q.pop();
        if(visit[next] == 1) continue;
        visit[next] = 1;
        ans += d;
        for(int i = 0; i < costs[next].size(); i++)
        {
            y = costs[next][i].first;
            d = costs[next][i].second;
            if(visit[y] == 0)
                q.push(make_pair(-d, y));
        }
        n++;
    }
    cout<<ans;
    return 0;
}
