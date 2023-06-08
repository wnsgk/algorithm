#include <bits/stdc++.h>
#define MAX_N 500001
using namespace std;

int n, t;
int sfx[MAX_N], lcp[MAX_N];
int g[MAX_N], ng[MAX_N], tmp[MAX_N];
string s;

bool compare(int a, int b){
	if(g[a] == g[b]) return g[a+t] < g[b+t];
	return g[a] < g[b];
}

void suffix_array(string str){
	t = 1;
	n = str.length();
	for(int i=0; i<n; i++){ 
	    sfx[i] = i; 
	    g[i] = str[i]-'a'; 
	}
	
	while(t<=n){
		g[n] = -1;
		sort(sfx, sfx+n, compare);
	    ng[sfx[0]] = 0;
		
		for(int i=1; i<n; i++){
			if(compare(sfx[i-1], sfx[i])) ng[sfx[i]] = ng[sfx[i-1]] + 1;
			else ng[sfx[i]] = ng[sfx[i-1]];
		}
		
		swap(g, ng);
		t*=2;
	}
}
 
void LCP(){
    int len = 0;
	for(int i=0; i<n; i++) tmp[sfx[i]] = i;
	for(int i=0; i<n; i++){
		if(tmp[i] > 0){
			int j = sfx[tmp[i]-1];
			while(s[j+len] == s[i+len]) len++;
			lcp[tmp[i]] = len;
			if(len > 0) len--;
		}
	}
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    suffix_array(s);
    LCP();
    for(int i = 0; i < n; i++) cout<<sfx[i]<<"\n";
    return 0;
}
