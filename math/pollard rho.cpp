/*
 * O(N^(1/4)) 소인수분해 알고리즘
 */
long long gcd(long long a, long long b){
    if(a < b) {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    if(b == 0) return a;
    return gcd(b, a%b);
}

long long pollard_rho(long long n){
    
    if(is_prime(n)) return n;

    if(n == 1) return 1;
    if(n%2 == 0) return 2;
    
    long long a, b, c, d;
    a = b = rand() % (n-2) + 2;
    c = rand() % 20 + 1;
    d = 1;
    
    while(d == 1){
        a = (((__int128)a * a % n) + c + n) % n;
        b = (((__int128)b * b % n) + c + n) % n;
        b = (((__int128)b * b % n) + c + n) % n;
        d = gcd(abs(a - b), n);
        if (d == n) return pollard_rho(n);
    }
    
    if(is_prime(d)) return d;
    else return pollard_rho(d);
}

vector<long long> prlist(long long n){
    
    vector<long long> v;
    
    while(n > 1) {
        long long d = pollard_rho(n);
        v.push_back(d);
        n /= d;
    }
    
    sort(v.begin(), v.end());
    
    return v;
}
