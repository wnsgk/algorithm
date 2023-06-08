#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x, grundy = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x;
        grundy ^= x;
    }
    if(grundy) cout<<"koosaga";
    else cout<<"cubelover";
    return 0;
}   
