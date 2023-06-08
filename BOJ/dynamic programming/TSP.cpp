#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int dp[16][1<<16], v[16][16];    //dp[i][j] : j만큼 방문하고 현재 i점에 있을 때의 값.

int tsp(int curr, int visit)
{
    if(visit == (1<<n) - 1)                    //모든 점을 방문하면 첫번째 점까지의 거리만큼 더해주고 끝냄.
    {
        if(v[curr][0] != 0)
            return v[curr][0];
        else return INT_MAX;
    }
    if(dp[curr][visit] != -1) return dp[curr][visit];    //이미 구했을 경우 그냥 return 해줌.
    dp[curr][visit] = INT_MAX;
    for(int i = 0; i < n; i++)                           //다음에 점 i를 방문했을 때 최솟값.
    {
        if((1<<i) & visit) continue;
        if(v[curr][i] != 0)
        {
            int next = tsp(i, visit | (1<<i));
            dp[curr][visit] = min(dp[curr][visit], next+v[curr][i]);
        }
    }
    return dp[curr][visit];
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &v[i][j]);
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < (1<<n); j++)
            dp[i][j] = -1;
            
    int ans = tsp(0, 1);                                //0번부터 시작하고 현재 0번만 방문함.
    
    cout<<ans;

    return 0;
}
