#include <bits/stdc++.h>
#define MAX_N 200002
using namespace std;

int pal[MAX_N];

void manacher(string str){
    string s;
    for(int i = 0; i < str.length(); i++){
        s += '#';
        s += str[i];
    }
    s += '#';
    
    int n = s.length(), r = 0, p = 0;
    for(int i = 0; i < n; i++){
        if(i <= r) pal[i] = min(pal[2*p-i], r-i);
        else pal[i] = 0;
        
        while(i - pal[i] - 1 >= 0 && i + pal[i] + 1 < n && s[i-pal[i]-1] == s[i+pal[i]+1]) pal[i]++;
        
        if(r < i + pal[i]){
            r = i + pal[i];
            p = i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    manacher(s);
    int ans = 0;
    for(int i = 0; i < s.length()*2+1; i++) ans = max(ans, pal[i]);
    cout<<ans;
    return 0;
}
