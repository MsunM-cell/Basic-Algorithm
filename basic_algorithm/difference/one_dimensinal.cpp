// 2021-08-10

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i] - a[i - 1];
    }

    int l, r, c;
    while (m--)
    {
        scanf("%d%d%d", &l, &r, &c);
        b[l] += c;
        b[r + 1] -= c;
    }

    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        printf("%d ", b[i]);
    }

    return 0;
}