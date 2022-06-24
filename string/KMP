#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> fail(string s) {
	int m = s.length();
	vector<int> pi(m);

	pi[0] = 0;
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> KMP(string t, string s) {
	int m = s.length(); 
	int n = t.length(); 
	vector<int> pos; 
	vector<int> pi = fail(s); 

	for(int i = 0, j = 0; i < n; i++) {
		while (j > 0 && t[i] != s[j])
			j = pi[j-1];
		if (t[i] == s[j]) { 
			if (j == m-1) { 
				pos.push_back(i-m+1);
				j = pi[j]; 
			}
			else j++; 
		}
	}
	return pos;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str, s;
    getline(cin, str);
    getline(cin, s);
    vector<int> ans = KMP(str, s);
    cout<<ans.size()<<"\n";
    for(int i = 0; i < ans.size(); i++) cout<<ans[i]+1<<" ";
}
