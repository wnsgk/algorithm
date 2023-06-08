for (int mask = 0; mask < (1 << sz); ++mask)
{
    int prod = 1;
    int cnt = 0;
    for (int j = 0; j < sz; ++j)
    {
        if (mask & (1 << j))
        {
            prod *= left_primes[j];
            cnt++;
        }
    }
    if (cnt % 2 == 0)
    {
        ans += till / prod;
    }
    else
    {
        ans -= till / prod;
    }
}
calculat[i.first] = ans;
