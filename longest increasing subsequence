#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//O(nlogn)
int main()
{
    int n, mx = 1;
    cin >> n;
    vector<int> seq(n + 1, 0); // 입력 수열
    vector<int> d(n + 1, 0);   // 길이가 k인 수열 중 마지막 원소가 가장 작은 값을 d[k]에 저장

    for (int i = 1; i < n + 1; i++)
        scanf("%d", &seq[i]);

    d[1] = seq[1];
    for (int i = 2; i < n + 1; i++)
    {
        if (seq[i] > d[mx]) //seq[i]가 d[mx]보다 클 경우 가장 긴 수열 길이가 증가함.
        {
            mx += 1;
            d[mx] = seq[i];
        }
        else
        {
            int idx = lower_bound(d.begin() + 1, d.begin() + mx, seq[i]) - d.begin(); // seq[i]보다 큰 가장 작은 값을 이진 탐색으로 찾아서 d[idx]를 바꾸어줌.
            d[idx] = seq[i];
        }
    }

    cout << mx;
    return 0;
}

//O(n^2)
int main() 
{
    int N, mx = 0;
    cin >> N;
    vector<int> v(N);  // 입력 수열
    vector<int> ans(N, 0);  // ans[i-1] = i까지 입력 받았을 때 가장 긴 수열
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        mx = 0;
        for (int j = 0; j < i; j++) {      //v[i]를 포함하는 가장 긴 수열을 찾기.
            if (v[j] < v[i]) {
                mx = max(mx, ans[j]);
            }
        }
        ans[i] = mx + 1;
    }
    mx = 0;
    for (int i = 0; i < N; i++) // 모든 ans에서 가장 긴 수열
        mx = max(mx, ans[i]);
    cout << mx;

    return 0;
}
