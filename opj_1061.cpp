#include <iostream>
using namespace std;

long long extend_euild(long long a, long long b, long long &x, long long &y)
{
    long long r, t;
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    r = extend_euild(b, a%b, x, y);
    t = x;
    x = y;
    y = t - a/b*y;
    return r;
}

int main()
{
    long long x, y, m, n, l, x1, y1;
    cin >> x >> y >> m >> n >> l;
    a = n-m;
    d = x-y;
    c = extend_euild(a, l, x1, y1);
    if(c%d)
        cout << "Impossible" << endl;
    else
    {
        b = b / c;
        d = d / c;
        long long v = d * x1;
        cout << (v%b+b)%b << endl;
    }
    return 0;
}