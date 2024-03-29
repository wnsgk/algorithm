/* 소수판별법
 * O(k*log^3n)
 */
 
long long power(long long x, long long y, long long p) {
    long long ret = 1;
    x = x % p;
    while(y > 0) {
        if(y & 1) ret = (__int128)ret*x%p;
        x = (__int128)x*x%p;
        y >>= 1;
    }
    return ret;
}

bool miller_rabin(long long x, long long a){
    int r = 0;
    long long d = x-1;
    while(d%2 == 0){
        r += 1;
        d /= 2;
    }
    long long y = power(a, d, x);
    if(y == 1 || y == x-1) return true;
    
    for(int i = 0; i < r-1; i++){
        y = power(y, 2, x);
        if(y == x-1) return true;
    }
    return false;
}

bool is_prime(long long x) {
    
    int p[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	
	for (auto& i : p) {
		if (x == i) return true;
		if (x > 40 && !miller_rabin(x, i)) return false;
	}

	if (x <= 40) return false;
	
	return true;
}
