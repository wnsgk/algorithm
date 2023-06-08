#include <iostream>
#include <vector>
#include <complex>

using namespace std;

typedef complex<double> cpx;
typedef long long ll;
const double PI = acos(-1);
vector<int> eratos(1000001, 1);
const int s = 1 << 21;

void fft(vector<cpx> &f, bool inv)
{
    int n = s;
    for(int i = 1, j = 0; i < n; ++i){
        int b = n/2;
        while(!((j ^= b) & b)) b /= 2;
        if(i < j) swap(f[i], f[j]);
    }
    for(int k = 1; k < n; k *= 2){
        double a = (inv ? M_PI/k : -M_PI/k);
        cpx w(cos(a), sin(a));
        for(int i = 0; i < n; i += k*2){
            cpx wp(1, 0);
            for(int j = 0; j < k; ++j){
                cpx x = f[i+j], y = f[i+j+k] * wp;
                f[i+j] = x + y;
                f[i+j+k] = x - y;
                wp *= w;
            }
        }
    }
    if(inv){
        for(int i = 0; i < n; ++i)
            f[i] /= n;
    }
}

vector<ll> multiply(vector<ll> &v)
{
	vector<cpx> fv(v.begin(), v.end());
	fv.resize(s);
	
	fft(fv, false);
	
	for(int i = 0; i < s; i++) fv[i] *= fv[i];
	
	fft(fv, true);
	
	vector<ll> ret(s);	
	for(int i = 0; i < s; i++) ret[i] = (ll)round(fv[i].real());
	
	return ret;
}


void make_prime() {
    ios::sync_with_stdio(false);
    int n = 1000001;
    for(int i = 2; i < n; i++) {
        if(eratos[i] == 0) continue;
        for(int j = i+i; j < n; j += i) {
            eratos[j] = 0;
        }
    }
    eratos[0] = 0;
    eratos[1] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    make_prime();
    vector<ll> a(1000000);

    for(int i = 0; i < 1000000; i++)
    {
        if(eratos[i] == 1) a[i] = 1;
    }
    vector<ll> c;
    c = multiply(a);
    while(t--){
        int n;
        cin>>n;
        if(c[n]%2 == 1) cout<<(c[n]-1)/2+1<<"\n";
        else cout<<c[n]/2<<"\n";
    }
    return 0;
}
