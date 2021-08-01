#include <iostream>
using namespace std;

long long midpow(long long x, long long y, long long m)
{
    if (x == 0)
        return 0;
    if (y == 0)
        return 1;
    long long u = midpow(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1)
        u = (u * x) % m;
    return u;
}
int main()
{
    long long x, y, m;
    cin >> x >> y >> m;
    cout << midpow(x, y, m);
    return 0;
}