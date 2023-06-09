#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin>>n>>m;
    vector<string> v(m);
    for(int i = 0; i < m; i++) cin>>v[i];
    
    deque<pair<int,int>> q;
    q.push_back({0, 0});
    int vst[m][n];
    memset(vst, 0, sizeof(vst));
    vst[0][0] = 1;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while(!q.empty()){
        int x = q.front().first/1000;
        int y = q.front().first%1000;
        int d = q.front().second;
        if(x == n-1 && y == m-1){
            cout<<d;
            break;
        }
        q.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || vst[ny][nx]) continue;
            vst[ny][nx] = 1;
            if(v[ny][nx] == '0'){
                q.push_front({nx*1000+ny, d});
            } else {
                q.push_back({nx*1000+ny, d+1});
            }
        }
    }
    return 0;
}
