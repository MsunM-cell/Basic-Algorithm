// 2021-08-08

#include <iostream>

using namespace std;

int main()
{
    double x;
    scanf("%lf", &x);

    double l = 0, r = x;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid >= x)
            r = mid;
        else
            l = mid;
    }

    printf("%lf", l);

    return 0;
}