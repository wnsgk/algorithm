// 가장 긴 증가하는 부분순열에서 수열의 길이와 부분 순열까지 출력하는 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, mx = 1;
    cin>>n;
    vector<int> seq(n+1,0);    //배열을 입력받음.
    vector<int> d1(n+1);       // n까지의 최대부분순열 길이
    vector<int> d2(n+1);        //d1[n]의 seq에서의 위치
    vector<int> m(n+1);         //m[n] = 부분순열에서 seq[n] 이전의 수의 index
    
    for(int i = 1; i < n+1; i++)
        scanf("%d", &seq[i]);
    
    d1[1] = seq[1];
    d2[1] = 1;
    for(int i = 2; i < n+1; i++)
    {
        if(seq[i] > d1[mx])
        {
            mx += 1;
            d1[mx] = seq[i];
            d2[mx] = i;
            m[i] = d2[mx-1];
            
        }
        else
        {
            int idx = lower_bound(d1.begin()+1, d1.begin()+mx, seq[i]) - d1.begin();
            m[i] = d2[idx-1];
            d1[idx] = seq[i];
            d2[idx] = i;
        }
    }
    
    cout<<mx<<endl;
    int a = d2[mx];
    vector<int> tmp;
    tmp.push_back(a);
    for(int i = 1; i < mx; i++)
    {
        tmp.push_back(m[a]);
        a = m[a];
    }
    for(int i = mx-1; i >= 0; i--)
    {
        printf("%d ", seq[tmp[i]]);
    }
    
    return 0;
}
