#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    int nCk[n+1][n+1];
    for(int i = 0; i <= n; i++) {
        nCk[i][0] = 1;
        nCk[i][i] = 1;
        for(int j = 1; j < i; j++) {
            nCk[i][j] = nCk[i-1][j-1] + nCk[i-1][j];
            nCk[i][j] %= 10007;
            nCk[i][i-j] = nCk[i][j];
        }
    }
    cout<<nCk[n][k];
    return 0;
}
